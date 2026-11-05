// roc 2012-06 00b10470  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10470
//
// 00b10470  e8eb44e7ff           call 0x984960
// 00b10475  50                   push eax
// 00b10476  e82326e7ff           call 0x982a9e
// 00b1047b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10470();
extern int __stdcall G2_func_00b10470(int);
int func_00b10470()
{
    return G2_func_00b10470(G1_func_00b10470());
}
