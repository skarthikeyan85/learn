# learn
Max in a vector:

1. double max = *max_element(vector.begin(), vector.end());
cout<<"Max value: "<<max<<endl;

2. 
  std::string str2 = str.substr (3,5);     // "think"
  5 chars from index 3 of string

  std::string str3 = str.substr (pos);     // get from "live" to the end
  get from index to end

  initialize string with a given length:
  std::string s6 (10, ' ');

3. vector can be initialized as:
  vector<int> vect1{ 1, 5, 4, 3, 2 };
  vector<int> vect2( 5); // vector.size
  vector<int> vect3( 5, 0); // vector.size, init value
  vector<int> vect4( vect1); // another vector

4. min heap:
priority_queue<int, vector<int>, greater<int>> p;
 max heap:
priority_queue<int> p;

5. min heap for a structure:
typedef struct attributes {
    int val;
    int index;
    bool operator>(const attributes& rhs) const
    {
        return val > rhs.val;
    }
} attribue_t;

priority_queue<attribue_t,vector<attribue_t>,greater<attribue_t> > pq;

6. sprintf in cpp:
ostringstream stringStream;
stringStream << arr[i] << ',' << arr[l] << ',' << arr[r];
string curr = stringStream.str();

7. random in range : high, low
rand()%(high - low + 1) + low

8. include in cpp file:
======================

#include <iostream>
#include <string>

using namespace std;

9. insert at the beginning of a vector:
======================================
  it = myvector.begin();
  it = myvector.insert ( it , 200 );

10. allocate in cpp: (with new):
  Node *root = new Node;

11. class has a vector:

class MyClass {
    int size;
    vector<int> vec;
}

MyClass::MyClass(int m_size) : size(m_size), vec(m_size, 0)
our second option:
vector<int> temp(size,0);
vec = temp;

12. atoi
to_string

13. walking over a map:
for (auto const& elem : adj)
    cout << elem.first << ' ' << elem.second << endl;

14. find in a vector:
    if (find(words.begin(), words.end(), start) == words.end()) {
    find in a map or set:
    if (adj.find(a) == adj.end()) {

15. array has a way to check emptyness    if (arr.empty())
    pass by reference can save time - due to cost of copying;
    2d array: do a:
        int N = arr.size();
        int M = arr[0].size();
    better to init strings:
        string pres("present");



