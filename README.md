# CSCI-103-Project-5-PageRank

You will write a program to rank webpages in an artificial webgraph. Your program will implement Pagerank algorithm
[1] used by Google to order search results. Pagerank is not the only algorithm used currently by google to order search
results, but it is the first used by the company[2].
This assignment requires you to create C++ classes to model objects in a webgraph such as webpages. You will also
use file I/O and stringstreams to read and write text files containing web information. Further, you will understand
how to implement directed graphs in C++ that represent webpages and their outbound links. Pages are represented
by vertices, while links between pages are directed edges connecting pages.
In this document, the word link is used interchangeably with hyperlink.

Pagerank [1] assigns numerical weights to pages in a webgraph. The purpose of the weights is to measure the importance
of a page among the rest. The algorithm attempts to model random surfer’s behavior who clicks on links at random.
The pagerank of a page represents the probability that a random surfer end up visiting that page.
Pagerank is defined as:
PR(A) = X [SIGMA] v∈BA {PR(v) / L(v)}
where P R(A) is the Pagerank of page A, P R(v) is the Pagerank of pages v which link to page A, L(v) is the number
of outbound links on page v, and BA is the set of pages that link to A

PRELAB:
This generates a random webgraph with 4 pages similar to the one in Figure 3. The graph description is at
mygraph.txt. A picture of the graph is at mygraph.png.
Calculate pageranks of the pages in the graph you generated. Let P R(id = k) be the page rank of the page
with id=k. Formulate four equations starting with PR(id = 0) + PR(id = 1) + PR(id = 2) + PR(id = 3) = 1
and solve them by any mean you want. Pageranks for pages in the graph shown in Figure 3 is: PR(id = 0) = 2/5, PR(id = 1) = 1/5, PR(id = 2) = 1/5, and  R(id = 3) = 1/5.

