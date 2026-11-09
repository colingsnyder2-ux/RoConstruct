// roc 2010-06 0081fb01  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0081fb01
//
// 0081fb01  b807fb8100           mov eax, 0x81fb07
// 0081fb06  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0081fb01()
{
    return &G;
}
