// roc 2011-06 0049c3fd  unit: VCWorkspace::?$CComObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0049c3fd
//
// 0049c3fd  b803c44900           mov eax, 0x49c403
// 0049c402  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0049c3fd()
{
    return &G;
}
