// roc 2011-06 0049dcff  unit: VCWorkspace::?$CComObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0049dcff
//
// 0049dcff  b805dd4900           mov eax, 0x49dd05
// 0049dd04  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0049dcff()
{
    return &G;
}
