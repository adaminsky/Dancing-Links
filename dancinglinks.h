#include <iostream>
#include <string>
using namespace std;

class Link {
private:
  int col;
  string Name;
  Link* LLink;
  Link* RLink;
  Link* DLink;
  Link* ULink;
  Link* CLink;
public:
  Link(Link* above, Link* left, Link* C = nullptr, string N = "");
  Link* getL();
  Link* getR();
  Link* getD();
  Link* getU();
  Link* getC();
  string getN();
  void setL(Link* L);
  void setR(Link* R);
  void setD(Link* D);
  void setU(Link* U);
  void setC(Link* C);
  void cover(Link* p);
  void uncover(Link* p);
};
