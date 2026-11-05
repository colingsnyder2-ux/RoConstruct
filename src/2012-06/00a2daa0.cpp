// roc 2012-06 00a2daa0  unit: CXTPReportInplaceEdit  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a2daa0
//
// 00a2daa0  b803000000           mov eax, 3
// 00a2daa5  c20c00               ret 0xc
// auto-matched from its assembly shape

struct S_func_00a2daa0 {

    unsigned int f(int a1, int a2, int a3);
};
unsigned int S_func_00a2daa0::f(int a1, int a2, int a3)
{
    return 3u;
}
