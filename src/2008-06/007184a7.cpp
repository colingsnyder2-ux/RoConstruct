// roc 2008-06 007184a7  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007184a7
//
// 007184a7  b8ad847100           mov eax, 0x7184ad
// 007184ac  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_007184a7()
{
    return &G;
}
