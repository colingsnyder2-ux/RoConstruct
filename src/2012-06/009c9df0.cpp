// roc 2012-06 009c9df0  unit: ATL::CRegObject  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c9df0
//
// 009c9df0  b801400080           mov eax, 0x80004001
// 009c9df5  c20c00               ret 0xc
// auto-matched from its assembly shape

struct S_func_009c9df0 {

    unsigned int f(int a1, int a2, int a3);
};
unsigned int S_func_009c9df0::f(int a1, int a2, int a3)
{
    return 0x80004001u;
}
