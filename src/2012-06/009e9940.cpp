// roc 2012-06 009e9940  unit: CXTColorDialog  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e9940
//
// 009e9940  b8347fc100           mov eax, 0xc17f34
// 009e9945  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e9940()
{
    return &G;
}
