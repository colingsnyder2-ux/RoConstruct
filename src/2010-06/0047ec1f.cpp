// roc 2010-06 0047ec1f  unit: VCWorkspace::?$CComObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047ec1f
//
// 0047ec1f  b825ec4700           mov eax, 0x47ec25
// 0047ec24  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0047ec1f()
{
    return &G;
}
