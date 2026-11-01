// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Element {
    char data[24];
};

struct S {
    Element* data;
    int count;
    Element* f();
};

#pragma optimize("", off)
Element* S::f()
{
    do {} while (0);
    do {} while (0);
    return data + (count - 1);
}
#pragma optimize("", on)