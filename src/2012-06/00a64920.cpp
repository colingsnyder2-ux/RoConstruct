// roc 2012-06 00a64920  unit: CXTPRichRender::XTextHost  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a64920
//
// 00a64920  b805400080           mov eax, 0x80004005
// 00a64925  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_00a64920 {

    unsigned int f(int a1);
};
unsigned int S_func_00a64920::f(int a1)
{
    return 0x80004005u;
}
