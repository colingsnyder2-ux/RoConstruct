// roc 2012-06 00b10c90  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10c90
//
// 00b10c90  e88b95eeff           call 0x9fa220
// 00b10c95  50                   push eax
// 00b10c96  e8031ee7ff           call 0x982a9e
// 00b10c9b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10c90();
extern int __stdcall G2_func_00b10c90(int);
int func_00b10c90()
{
    return G2_func_00b10c90(G1_func_00b10c90());
}
