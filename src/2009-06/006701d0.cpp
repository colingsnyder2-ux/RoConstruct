// from server: 100% by EspClaude
// from server: 82% by EspClaude
// roc 2009-06 006701d0  unit: RBX::Primitive  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006701d0
//

// from server: 100% by colin
// roc 2008-06 005e7c10  unit: RBX::Geometry  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7c10
//

#include <intrin.h>
// from server: 92% by king_originala
// roc 2008-06 005e7c10  unit: RBX::Geometry  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7c10
//

struct Geometry;

struct Node {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int predicate();
    virtual int kind();

    int padding[3];
    Geometry* owner;
    int reserved;
    int firstIndex;
    int secondIndex;
};

struct Geometry {
    char padding[0xa4];
    Node** nodes;
    int count;

    Node* find(Node* node);
};

Node* Geometry::find(Node* node) {
    while (node) {
        if (!node->predicate()) {
            int type = node->kind();
            if (type == 1 || type == 2)
                return node;
        }

        int index;
        if (this == node->owner)
            index = node->firstIndex;
        else
            index = node->secondIndex;

        int next = index + 1;
        if (next < count)
            node = nodes[next];
        else
            node = 0;
        _ReadWriteBarrier();
    }
    return 0;
}

