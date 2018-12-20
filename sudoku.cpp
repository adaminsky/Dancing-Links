#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int main() {
  // Get input.
  vector< pair<int, int> > clueij;
  vector<string> clues;
  string line;
  istringstream iss;
  while (getline(cin, line)) {
    iss.clear();
    iss.str(line);
    string p;
    iss >> p;
    clueij.push_back(make_pair(stoi(p.substr(1,1)), stoi(p.substr(2,1))));
    clues.push_back(line);
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << "p" << i << j << " ";
      cout << "b" << i << j+1 << " ";
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int k = 1; k <= 4; k++) {
      cout << "r" << i << k << " ";
      cout << "c" << i << k << " ";
    }
  }
  cout << endl;
  
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      vector< pair<int, int> >::iterator it = find(clueij.begin(), clueij.end(), make_pair(i, j));
      if (it != clueij.end()) {
	int d = distance(clueij.begin(), it);
	cout << clues[d] << endl;
	continue;
      }

      for (int k = 1; k <= 4; k++) {
	cout << "p" << i << j << " ";
	cout << "r" << i << k << " ";
	cout << "c" << j << k << " ";
	cout << "b" << (2*(i/2) + (j/2)) << k << endl;
      }
    }
  }
}
	
