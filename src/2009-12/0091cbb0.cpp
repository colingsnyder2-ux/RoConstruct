// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    unsigned int reserved;
    unsigned int value;
    void f();
};

#pragma optimize("", off)
void S::f()
{
    do {
    } while (0);
    value = 0;
}
#pragma optimize("", on)