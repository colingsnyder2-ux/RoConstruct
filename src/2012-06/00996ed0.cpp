// roc 2012-06 00996ed0  unit: CXTPCommandBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00996ed0
//
// 00996ed0  b830e4c000           mov eax, 0xc0e430
// 00996ed5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00996ed0()
{
    return &G;
}
