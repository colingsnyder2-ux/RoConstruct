// roc 2012-06 009846a0  unit: CXTPControlAction  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009846a0
//
// 009846a0  b8cccdc000           mov eax, 0xc0cdcc
// 009846a5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009846a0()
{
    return &G;
}
