// roc 2012-06 004b331a  unit: VCWorkspace::?$CComObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b331a
//
// 004b331a  b820334b00           mov eax, 0x4b3320
// 004b331f  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004b331a()
{
    return &G;
}
