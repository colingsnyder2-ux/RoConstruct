// from server: 100% by king_originala
struct S {
    char padding[28];
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
