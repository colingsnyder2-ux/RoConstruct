// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct It {
    int a, b;
    It(void* x, void* y, void* z);
    ~It();
};
It make(void* x, void* y, void* z)
{
    return It(x, y, z);
}
