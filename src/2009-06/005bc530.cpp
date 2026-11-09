// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct It {
    int a, b;
    ~It();
};
struct C {
    It make(int a, int b, int c) const;
    It begin() const;
};
It C::begin() const
{
    return make(0, 0, 0);
}
