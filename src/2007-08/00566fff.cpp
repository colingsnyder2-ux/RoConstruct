// roc 2007-08 00566fff  unit: TextXmlWriterWithEmbeddedContent  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00566fff
//
// 00566fff  b805705600           mov eax, 0x567005
// 00567004  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00566fff()
{
    return &G;
}
