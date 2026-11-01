// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct It {
    int a, b;
    It(void* x, void* y);
    ~It();
};
It make(void* x, void* y)
{
    return It(x, y);
}
