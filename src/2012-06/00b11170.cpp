// roc 2012-06 00b11170  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11170
//
// 00b11170  e85be0f5ff           call 0xa6f1d0
// 00b11175  50                   push eax
// 00b11176  e82319e7ff           call 0x982a9e
// 00b1117b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b11170();
extern int __stdcall G2_func_00b11170(int);
int func_00b11170()
{
    return G2_func_00b11170(G1_func_00b11170());
}
