// roc 2012-06 009e8d50  unit: CXTColorDialog  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e8d50
//
// 009e8d50  b8407dc100           mov eax, 0xc17d40
// 009e8d55  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e8d50()
{
    return &G;
}
