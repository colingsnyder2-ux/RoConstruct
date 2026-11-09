// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct Key { int a, b; unsigned v[12]; };
struct H { unsigned operator()(const Key& k) const; };
unsigned H::operator()(const Key& k) const
{
    const unsigned* p = k.v;
    unsigned h = 0;
    for (unsigned i = 0; i < 12; ++i) { h ^= *p; ++p; }
    return h;
}
