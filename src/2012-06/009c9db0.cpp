// roc 2012-06 009c9db0  unit: CXTPToolTipContext::CHTMLToolTip::XOleClientSite  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c9db0
//
// 009c9db0  b801400080           mov eax, 0x80004001
// 009c9db5  c20400               ret 4
// auto-matched from its assembly shape

struct S_func_009c9db0 {

    unsigned int f(int a1);
};
unsigned int S_func_009c9db0::f(int a1)
{
    return 0x80004001u;
}
