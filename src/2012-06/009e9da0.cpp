// roc 2012-06 009e9da0  unit: CXTPToolTipContext::CHTMLToolTip::XOleClientSite  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e9da0
//
// 009e9da0  b801400080           mov eax, 0x80004001
// 009e9da5  c21000               ret 0x10
// auto-matched from its assembly shape

struct S_func_009e9da0 {

    unsigned int f(int a1, int a2, int a3, int a4);
};
unsigned int S_func_009e9da0::f(int a1, int a2, int a3, int a4)
{
    return 0x80004001u;
}
