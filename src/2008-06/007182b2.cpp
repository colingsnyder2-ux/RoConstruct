// roc 2008-06 007182b2  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007182b2
//
// 007182b2  b8b8827100           mov eax, 0x7182b8
// 007182b7  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_007182b2()
{
    return &G;
}
