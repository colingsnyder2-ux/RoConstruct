// roc 2012-06 00b10b80  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10b80
//
// 00b10b80  e82bacebff           call 0x9cb7b0
// 00b10b85  50                   push eax
// 00b10b86  e8131fe7ff           call 0x982a9e
// 00b10b8b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10b80();
extern int __stdcall G2_func_00b10b80(int);
int func_00b10b80()
{
    return G2_func_00b10b80(G1_func_00b10b80());
}
