// roc 2012-06 00b10c10  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10c10
//
// 00b10c10  e83b1becff           call 0x9d2750
// 00b10c15  50                   push eax
// 00b10c16  e8831ee7ff           call 0x982a9e
// 00b10c1b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10c10();
extern int __stdcall G2_func_00b10c10(int);
int func_00b10c10()
{
    return G2_func_00b10c10(G1_func_00b10c10());
}
