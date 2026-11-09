// roc 2012-06 00b10490  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10490
//
// 00b10490  e8fbe1e7ff           call 0x98e690
// 00b10495  50                   push eax
// 00b10496  e80326e7ff           call 0x982a9e
// 00b1049b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10490();
extern int __stdcall G2_func_00b10490(int);
int func_00b10490()
{
    return G2_func_00b10490(G1_func_00b10490());
}
