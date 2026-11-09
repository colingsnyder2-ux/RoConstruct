// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_8bcd28e9235df2a2.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
void* __cdecl operator new(unsigned int);


struct Vector3 {
    unsigned int x, y, z;
};

struct Grid {
    unsigned int x, y, z;
    Grid() : x(0), y(0), z(0) {}
    Grid& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
};

struct Node {
    unsigned short children[8];
    unsigned short category;
    unsigned char flag;
    unsigned char padding;
    unsigned int state;
    unsigned int index;
    Grid position;
    Node* next;

    Node();
    void reset();
};

inline void Node::reset()
{
    unsigned short invalid = 65535;
    state = 0;
    category = invalid;
    index = ~0u;
    next = 0;
    flag = 0;
    for (int i = 0; i < 8; i++)
        children[i] = invalid;
}

inline Node::Node()
{
    reset();
}

struct Entry {
    unsigned int value;
    Node* head;
};

typedef std::vector<Entry> Group;

struct S {
    unsigned int count;
    unsigned int padding[2];
    Group groups[4];
    unsigned int reserved[2];
    Node* freeList;

    Node* f(unsigned int category, unsigned int index,
            const Vector3& position);
};

Node* S::f(unsigned int category, unsigned int index,
           const Vector3& position)
{
    Node* node = freeList;
    if (node) {
        freeList = node->next;
        node->reset();
    } else {
        node = new Node;
        ++count;
    }

    node->state = 0;
    node->category = static_cast<unsigned short>(category);
    node->index = index;
    node->position = position;

    Group& group = groups[category];
    node->next = group[index].head;

    group[index].head = node;
    return node;
}

