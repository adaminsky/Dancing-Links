#include "dancinglinks.h"
#include <iostream>
#include <new>
using namespace std;

void solve(Link* r, int k);
void createHeaders(Link* h, string arr[], int size);
void addOptions(string options[], int size, Link* h);
Link* O[4];

int main() {
  ///////////////////////////////////////////////////////////////////////
  // // Creating column headers					       //
  // Link* spacer = new Link(nullptr, nullptr);			       //
  // Link* a = new Link(nullptr, spacer, nullptr, "a");		       //
  // Link* b = new Link(nullptr, a, nullptr, "b");		       //
  // Link* c = new Link(nullptr, b, nullptr, "c");		       //
  // c->setR(spacer);						       //
  // spacer->setL(c);						       //
  // 								       //
  // // Adding "links" for each of the ones in the columns and linking //
  // // them appropriately.					       //
  // Link* one = new Link(a, nullptr, a);			       //
  // one->setD(a);						       //
  // Link* two = new Link(b, nullptr, b);			       //
  // two->setD(b);						       //
  // b->setU(two);						       //
  // Link* three = new Link(one, nullptr, a);			       //
  // three->setD(a);						       //
  // a->setU(three);						       //
  // Link* four = new Link(c, three, c);			       //
  // four->setD(c);						       //
  // c->setU(four);						       //
  // four->setR(three);						       //
  // three->setL(four);						       //
  // 								       //
  // solve(spacer, 0);						       //
  ///////////////////////////////////////////////////////////////////////

  string testHeaders[] = {"a", "b", "c"};
  string options1[] = {"a", "c"};
  string options2[] = {"b"};
  string options3[] = {"a"};

  Link* h = new Link(nullptr, nullptr, nullptr, "");
  createHeaders(h, testHeaders, 3);
  addOptions(options1, 2, h);
  addOptions(options2, 1, h);
  addOptions(options3, 1, h);

  solve(h, 0);
}

void createHeaders(Link* h, string arr[], int size) {
  Link* tmp = h;
  for (int i = 0; i < size; i++) {
    tmp = new Link(nullptr, tmp, nullptr, arr[i]);
  }
}

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
      
