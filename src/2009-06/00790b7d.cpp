// roc 2009-06 00790b7d  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00790b7d
//
// 00790b7d  b8830b7900           mov eax, 0x790b83
// 00790b82  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00790b7d()
{
    return &G;
}
