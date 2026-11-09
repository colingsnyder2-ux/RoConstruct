// roc 2012-06 0043a75e  unit: CSelectionPropGrid  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0043a75e
//
// 0043a75e  b864a74300           mov eax, 0x43a764
// 0043a763  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0043a75e()
{
    return &G;
}
