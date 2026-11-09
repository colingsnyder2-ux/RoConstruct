// roc 2012-06 009de680  unit: CXTPTabClientWnd::CWorkspace  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009de680
//
// 009de680  b8c068c100           mov eax, 0xc168c0
// 009de685  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009de680()
{
    return &G;
}
