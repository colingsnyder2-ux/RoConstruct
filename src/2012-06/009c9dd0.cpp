// roc 2012-06 009c9dd0  unit: CPatchedControlComboBox  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c9dd0
//
// 009c9dd0  b801400080           mov eax, 0x80004001
// 009c9dd5  c21800               ret 0x18
// auto-matched from its assembly shape

struct S_func_009c9dd0 {

    unsigned int f(int a1, int a2, int a3, int a4, int a5, int a6);
};
unsigned int S_func_009c9dd0::f(int a1, int a2, int a3, int a4, int a5, int a6)
{
    return 0x80004001u;
}
