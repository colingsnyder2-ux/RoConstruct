// roc 2012-06 009e9d80  unit: CXTPToolTipContext::CHTMLToolTip::XOleClientSite  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e9d80
//
// 009e9d80  b801400080           mov eax, 0x80004001
// 009e9d85  c20800               ret 8
// auto-matched from its assembly shape

struct S_func_009e9d80 {

    unsigned int f(int a1, int a2);
};
unsigned int S_func_009e9d80::f(int a1, int a2)
{
    return 0x80004001u;
}
