// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_indexedslotvector_835331620cc5d81a.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
extern unsigned int nextIndex;
struct Node {virtual ~Node(); int value; Node():value(0) {}};
struct S {std::vector<Node*> slots; static unsigned int index(){static unsigned int value=nextIndex++;return value;} int* f();};
int* S::f(){while(slots.size()<=index()) slots.push_back(0);Node*& slot=slots[index()];if(!slot) slot=new Node;return &slot->value;}
