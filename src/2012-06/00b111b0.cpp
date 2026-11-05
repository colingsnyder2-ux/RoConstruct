// roc 2012-06 00b111b0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b111b0
//
// 00b111b0  e8bb43f6ff           call 0xa75570
// 00b111b5  50                   push eax
// 00b111b6  e8e318e7ff           call 0x982a9e
// 00b111bb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b111b0();
extern int __stdcall G2_func_00b111b0(int);
int func_00b111b0()
{
    return G2_func_00b111b0(G1_func_00b111b0());
}
