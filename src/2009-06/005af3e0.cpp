// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("", off)

struct S {
    char padding[0x28];
    int value;
    void setValue(int v);
};

void S::setValue(int v) {
    value = v;
}