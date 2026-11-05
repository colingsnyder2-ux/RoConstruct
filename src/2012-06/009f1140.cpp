// roc 2012-06 009f1140  unit: CXTPPropertyGridToolTip  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f1140
//
// 009f1140  b83091c100           mov eax, 0xc19130
// 009f1145  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f1140()
{
    return &G;
}
