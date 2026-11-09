// roc 2012-06 009c9dc0  unit: CPatchedControlComboBox  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c9dc0
//
// 009c9dc0  b801400080           mov eax, 0x80004001
// 009c9dc5  c21400               ret 0x14
// auto-matched from its assembly shape

struct S_func_009c9dc0 {

    unsigned int f(int a1, int a2, int a3, int a4, int a5);
};
unsigned int S_func_009c9dc0::f(int a1, int a2, int a3, int a4, int a5)
{
    return 0x80004001u;
}
