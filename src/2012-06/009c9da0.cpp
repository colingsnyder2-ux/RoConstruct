// roc 2012-06 009c9da0  unit: CXTPAccessible::XAccessible  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c9da0
//
// 009c9da0  b801400080           mov eax, 0x80004001
// 009c9da5  c22400               ret 0x24
// auto-matched from its assembly shape

struct S_func_009c9da0 {

    unsigned int f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);
};
unsigned int S_func_009c9da0::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    return 0x80004001u;
}
