// from server: 100% by atomic.potato
struct Node {
    char pad0[8];
    int field8;
    char padC[4];
    int field10;
    int field14;
    int field18;
    int field1C;
};

struct Arg1 {
    char pad0[8];
    unsigned char field8;
    char pad9[3];
    int fieldC;
    int field10;
    int field14;
};

struct Arg2 {
    char pad0[8];
    int field8;
};

extern Node g_default;

Node* find(Arg1* a, Arg2* b) {
    unsigned int mask = (1u << a->field8) - 1;
    unsigned int idx = mask & (unsigned int)b->field8;
    Node* n = (Node*)(a->field14 + (idx << 5));
    while (n->field18 != 4 || n->field10 != (int)b) {
        n = (Node*)n->field1C;
        if (n == 0) {
            return &g_default;
        }
    }
    return n;
}
