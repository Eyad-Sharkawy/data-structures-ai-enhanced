#include <iostream>
#include "Doubly_Linked_List.h"
using namespace std;

int main () {
    Doubly_Linked_List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    Doubly_Linked_List<int>::iterator it = l.begin();

    for (auto i =l.begin(); i != l.end(); ++i) {
        cout << *i << endl;
    }

    return 0;
}
