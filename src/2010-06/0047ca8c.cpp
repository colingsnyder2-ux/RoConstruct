// roc 2010-06 0047ca8c  unit: VCWorkspace::?$CComObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047ca8c
//
// 0047ca8c  b892ca4700           mov eax, 0x47ca92
// 0047ca91  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0047ca8c()
{
    return &G;
}
