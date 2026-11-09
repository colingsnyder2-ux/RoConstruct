// roc 2012-06 009e9d40  unit: CXTPToolTipContext::CHTMLToolTip  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e9d40
//
// 009e9d40  b8d87fc100           mov eax, 0xc17fd8
// 009e9d45  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e9d40()
{
    return &G;
}
