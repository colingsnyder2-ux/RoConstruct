// roc 2011-06 0087cfdb  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0087cfdb
//
// 0087cfdb  b8e1cf8700           mov eax, 0x87cfe1
// 0087cfe0  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0087cfdb()
{
    return &G;
}
