// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: 8-byte element {payload, float sort key at +4}; 3-element sorting network, cdecl.
struct KeyedPair {
    int value;
    float key;
};

static inline void swapPair(KeyedPair* a, KeyedPair* b)
{
    if (a != b) {
        KeyedPair t = *a;
        *a = *b;
        *b = t;
    }
}

extern "C" void fn_0067c800(KeyedPair* a, KeyedPair* b, KeyedPair* c)
{
    if (a->key > b->key)
        swapPair(b, a);
    if (b->key > c->key)
        swapPair(c, b);
    if (a->key > b->key)
        swapPair(b, a);
}
