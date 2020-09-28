#ifndef PAGE_H
#define PAGE_H
#include <string>
using std::string;
#include<vector>
using std::vector;
class Page { 
    public:
        Page();
        Page(int, string, double, vector<int>);
        //getters
        int get_id();
        double get_rank();
        string get_url();
        vector<int> get_link();
        int getLinkSize();
        //setters
        void set_id(int n);
        void set_url(string s);
        void add_link(int link);
        void set_prank(double r);
        void setLinks(vector<int> &v);
        void setLinkSize(int n);
    
    private:
        //Data members: id, url, pagerank, links , .. etc
        int id;
        string url;
        vector <int> links;
        double pagerank;
        int linksize;
};  
#endif
