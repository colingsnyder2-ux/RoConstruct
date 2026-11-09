// roc 2012-06 00b10ce0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10ce0
//
// 00b10ce0  e81bd4f0ff           call 0xa1e100
// 00b10ce5  50                   push eax
// 00b10ce6  e8b31de7ff           call 0x982a9e
// 00b10ceb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10ce0();
extern int __stdcall G2_func_00b10ce0(int);
int func_00b10ce0()
{
    return G2_func_00b10ce0(G1_func_00b10ce0());
}
