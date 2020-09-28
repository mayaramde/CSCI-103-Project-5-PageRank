#include "web.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;

Web::Web() 
{ 

}

Web::~Web() 
{ 
    
}

//reading in graph
bool Web::read_graph(const char *filename) 
{ 
    ifstream ifile;
    string s;
    unsigned int numPages; // number of pages
    int pageID;
    string url;
    double prank;
    vector<int> v;
    
    // Check if file can be opened
    ifile.open(filename);
    if (ifile.fail()) {
        cout << "Couldn't open file" << endl;
        ifile.close();
        return false;
    }
    
    ifile >> numPages; // get the number of pages in file
    if (ifile.fail()) {
        return false;
    }
    
    pages.resize(numPages);
    for (unsigned int i = 0; i < numPages; i++) {
        ifile >> pageID;
        pages[i].set_id(pageID);
        ifile >> url;
        pages[i].set_url(url);
        ifile >> prank;
        pages[i].set_prank(prank);
        ifile.ignore();
        ifile.ignore();
        getline(ifile, s);
        stringstream ss(s);
        int num;
        while (ss >> num) {
            v.push_back(num);
        }
        pages[i].setLinks(v);
        pages[i].setLinkSize(v.size());
        v.clear();
    }
    
    ifile.close();
    return true;

}

bool Web::write_graph(const char *filename)
{ 
    // Check if i can write in file
    vector<int> plinks;
    ofstream myfile(filename);
    if (myfile.fail()) {
        return false;
    }
    
    // first line = # of pages in file
    stringstream ss;
    myfile << pages.size() << endl;
    
    // For each page in the file, load it's id, url, pagerank, and links
    for (int i = 0; i < pages.size(); i++) {
        myfile << pages[i].get_id() << endl;
        myfile << "\t" << pages[i].get_url() << endl;
        myfile << "\t" << pages[i].get_rank() << endl;
        
        plinks = pages[i].get_link();
        myfile << "\t";
        for (int j = 0; j < (unsigned int)plinks.size(); j++) {
            myfile << plinks[j] << " ";
        }
        myfile << endl;
    }
    myfile.close();
    return true;
    

}

void Web::calculate_rank(int S,int N)
{
    walker.resize(N);
    double pRank; 
    int s = 0;
    
    // evenly spread the walkers
    for (int y = 0; y < N; y++) {
        walker[y] = pages[y % pages.size()].get_id();
    }
    
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < N; j++) {
            walker[j] = pages[walker[j]].get_link()[rand() % pages[walker[j]].getLinkSize()];
        }
    }
    
    // Calculate rank
    while (pages.size() > s) {
        map<int, int> _map;

		for (vector<int>::iterator val = walker.begin(); val != walker.end(); ++val) {
			_map[*val]++;
		}

		pRank = (double)_map[s] / N;
		pages[s++].set_prank(pRank);
    }
}
