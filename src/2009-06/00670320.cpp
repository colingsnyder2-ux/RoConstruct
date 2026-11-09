// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e7d30  unit: RBX::Geometry  size: 74 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e7d30
//

struct S {
    char padding[0x88];
    int* values;
    int count;
    int reserved;
    S** neighbors;
};

int __cdecl findConnection(S* a, S* b)
{
    S* smaller = a->count < b->count ? a : b;
    S* other = smaller == a ? b : a;

    for (int i = 0; i < smaller->count; ++i) {
        if (smaller->neighbors[i] == other)
            return smaller->values[i];
    }

    return 0;
}
