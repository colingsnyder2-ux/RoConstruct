// from server: 75% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace ns_d {
struct Base { char pad[0x1d4]; ~Base(); };
struct Node;
struct L {
    Node* head;
    int size;
    void clear();
    ~L() { clear(); ::operator delete(head); }
};
struct Derived : Base {
    L m;
    ~Derived();
};
Derived::~Derived() {}
}