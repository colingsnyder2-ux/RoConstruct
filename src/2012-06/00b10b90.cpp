// roc 2012-06 00b10b90  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10b90
//
// 00b10b90  e84bb1ebff           call 0x9cbce0
// 00b10b95  50                   push eax
// 00b10b96  e8031fe7ff           call 0x982a9e
// 00b10b9b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10b90();
extern int __stdcall G2_func_00b10b90(int);
int func_00b10b90()
{
    return G2_func_00b10b90(G1_func_00b10b90());
}
