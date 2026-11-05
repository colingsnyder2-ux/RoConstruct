// roc 2012-06 00b111d0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b111d0
//
// 00b111d0  e8db58f6ff           call 0xa76ab0
// 00b111d5  50                   push eax
// 00b111d6  e8c318e7ff           call 0x982a9e
// 00b111db  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b111d0();
extern int __stdcall G2_func_00b111d0(int);
int func_00b111d0()
{
    return G2_func_00b111d0(G1_func_00b111d0());
}
