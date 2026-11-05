// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_9c71f42f11bab8d6.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
struct Node;
struct Geometry {
    char data[0x3c];
    int count;
    Node* getContact(int index);
    int numContacts() const { return count; }
};

struct Node {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual int getType();
    char data[8];
    Geometry *first;
    Geometry *second;
    Geometry* otherPrimitive(const Geometry* g) const { return (g == first) ? second : first; }
};

struct Collection {
    void remove(Node *node);
};

static bool inIgnoreGroup(std::set<Geometry*>* g, Geometry* p) { return g != NULL && g->find(p) != g->end(); }
struct S {
    char data[0x20];
    Collection collection;
    char padding[0x84];
    bool changing;
    void f(Geometry *geometry, std::set<Geometry*>* filter);
};

void S::f(Geometry *geometry, std::set<Geometry*>* filter)
{
    for (int index = geometry->numContacts() - 1; index >= 0; --index) {
        Node *node = geometry->getContact(index);
        int type = node->getType();
        if (type == 9 || type == 5)
            continue;

        Geometry *other = node->otherPrimitive(geometry);

        if (!inIgnoreGroup(filter, other)) {
            changing = true;
            collection.remove(node);
            changing = false;
        }
    }
}
