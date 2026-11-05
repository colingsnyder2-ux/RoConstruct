// roc 2012-06 00b11190  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11190
//
// 00b11190  e8abfaf5ff           call 0xa70c40
// 00b11195  50                   push eax
// 00b11196  e80319e7ff           call 0x982a9e
// 00b1119b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b11190();
extern int __stdcall G2_func_00b11190(int);
int func_00b11190()
{
    return G2_func_00b11190(G1_func_00b11190());
}
