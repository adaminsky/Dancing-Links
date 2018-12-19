#include "dancinglinks.h"
#include <string>
using namespace std;

// Remove all rows in p's list from the other column lists they are
// in.
void Link::cover(Link* p) {
  p->getR()->setL(p->getL());
  p->getL()->setR(p->getR());
  
  // Iterate through the items in p's column.
  for (Link* i = p->getD(); i != p; i = i->getD()) {
    
    // Iterate through the items in i's row and remove them from their
    // respective columm list.
    for (Link* j = i->getR(); j != i; j = j->getR()) {
      j->getD()->setU(j->getU());
      j->getU()->setD(j->getD());
    }
  }
}

// Reverse everything done by cover.
void Link::uncover(Link* p) {
  for (Link* i = p->getU(); i != p; i = i->getU()) {
    for (Link* j = i->getL(); j != i; j = j->getL()) {
      j->getD()->setU(j);
      j->getU()->setD(j);
    }
  }
  p->getR()->setL(p);
  p->getL()->setR(p);
}
  

Link::Link(Link* above, Link* left, Link* C, string N) {
  if (above) {
    above->setD(this);
    setU(above);
  }
  else {
    setD(this);
    setU(this);
  }
  if (left) {
    left->setR(this);
    setL(left);
  }
  else {
    setL(this);
    setR(this);
  }
  setC(C);
  Name = N;
}

Link* Link::getL() {
  return LLink;
}

string Link::getN() {
  return Name;
}

Link* Link::getR() {
  return RLink;
}

Link* Link::getD() {
  return DLink;
}

Link* Link::getU() {
  return ULink;
}

Link* Link::getC() {
  return CLink;
}

void Link::setL(Link* L) {
  LLink = L;
}

void Link::setR(Link* R) {
  RLink = R;
}

void Link::setD(Link* D) {
  DLink = D;
}

void Link::setU(Link* U) {
  ULink = U;
}

void Link::setC(Link* C) {
  CLink = C;
}

////////////////////////////////////////////////////
// void Link::remove() {			  //
//   Link* col = this->getD();			  //
//   while (col != this) {			  //
//       Link* row = col->getR();		  //
//       while (row != this) {			  //
// 	row->getL()->setR(row->getR());		  //
// 	row->getR()->setL(row->getL());		  //
// 	row = row->getR();			  //
//       }					  //
//       col->getU()->setD(col->getD());	  //
//       col->getD()->setU(col->getU());	  //
//       col = col->getD();			  //
//   }						  //
// }						  //
////////////////////////////////////////////////////

/////////////////////////////
// void Link::add() {	   //
//   Link* ptr = this;	   //
//   Link* l = getL();	   //
//   Link* r = getR();	   //
//   setR(l) = ptr;	   //
//   setL(r) = ptr;	   //
//   prt = ptr->getU();	   //
//   while (ptr != this) { //
//     Link* q = ptr - 1;  //
//     while (q != ptr) {  //
//       Link* x = 	   //
/////////////////////////////
