#include "dancinglinks.h"
#include <iostream>
#include <new>
#include <sstream>
using namespace std;

void solve(Link* r, int k);
void createHeaders(Link* h, string arr[], int size);
void addOptions(string options[], int size, Link* h);
Link* O[1000];

int main() {
  // Creating the "master" head node.
  Link* h = new Link(nullptr, nullptr, nullptr, "");

  string headers[1000];
  int size = 0;
  string c;
  string line;
  getline(cin, line);
  istringstream iss(line);
  while(iss >> c) {
    headers[size] = c;
    size++;
  }
  createHeaders(h, headers, size);

  while(getline(cin, line)) {
    iss.clear();
    iss.str(line);
    string options[4];
    int i = 0;
    while(iss >> c) {
      options[i] = c;
      i++;
    }
    addOptions(options, i, h);
  }

  solve(h, 0);
}

// Create the nodes that represent the columns of the linked list.
void createHeaders(Link* h, string arr[], int size) {
  Link* tmp = h;
  for (int i = 0; i < size; i++) {
    tmp = new Link(nullptr, tmp, nullptr, arr[i]);
  }
}

// Add each option under its appropriate header and correctly link
// them together.
void addOptions(string options[], int size, Link* h) {
  Link* add;
  for (int i = 0; i < size; i++) {
    Link* tmp = h;
    while (tmp->getN() != options[i])
      tmp = tmp->getR();
    if (i == 0)
      add = new Link(tmp, nullptr, tmp);
    else
      add = new Link(tmp, add, tmp);
  }
}   

// Recursively solve the exact cover problem using dancing links.
void solve(Link* r, int k) {
  Link* c = r->getR();
  if (c == r) {
    printf("Success! %i\n", k);
    for (int w = 0; w < k; w++) {
      printf("Row %i: ", w+1);
      cout << O[w]->getC()->getN();
      for (Link* n = O[w]->getR(); n != O[w]; n = n->getR()) {
	cout << ", " << n->getC()->getN();
      }
      cout << endl;
    }
    return;
  }
  c->cover(c);
  for (Link* i = c->getD(); i != c; i = i->getD()) {
    // Set O_k <- r;
    O[k] = i;
    Link* tmp = i;
    for (Link* j = i->getR(); j != i; j = j->getR()) {
      j->getC()->cover(j->getC());
    }
    solve(r, k+1);
    i = tmp;
    c = i->getC();
    for (Link* j = i->getL(); j != i; j = j->getL()) {
      j->uncover(j->getC());
    }
  }
  c->uncover(c);
  return;
}
      
