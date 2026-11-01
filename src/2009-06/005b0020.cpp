// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct Holder { int a; int b; double value; };
double getHolderValue(const Holder* h)
{
    return h->value;
}
