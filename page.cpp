#include "page.h"
#include <vector>
#include <iostream>
// constructors'
Page::Page() {
    pagerank = 0.0;
}

Page::Page(int n, string s, double r, vector<int> v) {
    id = n;
    url = s;
    pagerank = r;
    links = v;
}

// getters

int Page::get_id() {
    return id;
}

string Page::get_url() {
    return url;
}

vector<int> Page::get_link() {
    return links;
}

double Page::get_rank() {
    return pagerank;
}

int Page::getLinkSize() {
    return (int) links.size();
}

//setters
void Page::set_id(int n) {
    id = n;
}

void Page::set_url(string s) {
    url = s;
}

void Page::set_prank(double r) {
    pagerank = r;
}

void Page::setLinks(vector<int> &v) {
    links = v;
}

void Page::setLinkSize(int n) {
    linksize = n;
}

