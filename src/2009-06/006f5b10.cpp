// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <set>

struct Node {
    char storage[0x28];
    Node(void*);
};

struct E { int v[2]; };
bool operator<(const E&, const E&);
typedef std::set<E> SetMember;

struct ListHead {
    ListHead* next;
    ListHead* prev;
    ListHead() { next = this; prev = this; }
};

struct Parent {
    void* first;
    Node* node;
    void* second;
    Parent(void*, Node*, void*);
    virtual ~Parent();
};

inline Parent::Parent(void* a, Node* n, void* b)
    : first(a), node(n), second(b)
{
}

struct S : Parent {
    SetMember member;
    int count;
    ListHead head;
    S(void*, void*);
    virtual ~S();
};

S::S(void* a, void* b)
    : Parent(a, new Node(this), b), count(0)
{
}
