// roc 2012-06 004310ae  unit: CSelectionTreeCtrl  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004310ae
//
// 004310ae  b8b4104300           mov eax, 0x4310b4
// 004310b3  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004310ae()
{
    return &G;
}
