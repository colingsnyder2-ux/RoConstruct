// roc 2012-06 009ee360  unit: CXTPPropertyGridView  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ee360
//
// 009ee360  b8d88bc100           mov eax, 0xc18bd8
// 009ee365  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009ee360()
{
    return &G;
}
