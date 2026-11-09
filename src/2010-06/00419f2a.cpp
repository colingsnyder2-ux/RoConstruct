// roc 2010-06 00419f2a  unit: InsertObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00419f2a
//
// 00419f2a  b80d9f4100           mov eax, 0x419f0d
// 00419f2f  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00419f2a()
{
    return &G;
}
