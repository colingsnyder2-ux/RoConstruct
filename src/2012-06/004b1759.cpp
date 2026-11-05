// roc 2012-06 004b1759  unit: VCWorkspace::?$CComObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b1759
//
// 004b1759  b85f174b00           mov eax, 0x4b175f
// 004b175e  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004b1759()
{
    return &G;
}
