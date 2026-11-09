// roc 2012-06 009f9bf0  unit: CXTPControlGallery  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f9bf0
//
// 009f9bf0  b8d054e000           mov eax, 0xe054d0
// 009f9bf5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f9bf0()
{
    return &G;
}
