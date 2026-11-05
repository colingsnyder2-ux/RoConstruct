// from server: 100% by atomic.potato
struct RBX_BallCellContact {
    char pad0[8];
    unsigned char field8;
    char pad9[0xB];
    void* field14;
};

struct OtherThing {
    char pad0[8];
    unsigned int field8;
};

struct Node {
    char pad0[0x10];
    OtherThing* field10;
    int field14;
    int field18;
    Node* field1c;
};

extern Node g_default;

Node* find_node(RBX_BallCellContact* self, OtherThing* other) {
    unsigned int mask = (1u << self->field8) - 1u;
    unsigned int idx = mask & other->field8;
    Node* node = (Node*)((char*)self->field14 + (idx << 5));
    while (node->field18 != 4 || node->field10 != other) {
        node = node->field1c;
        if (node == 0) {
            return &g_default;
        }
    }
    return node;
}
