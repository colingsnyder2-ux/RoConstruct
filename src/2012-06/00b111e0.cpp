// roc 2012-06 00b111e0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b111e0
//
// 00b111e0  e80b59f6ff           call 0xa76af0
// 00b111e5  50                   push eax
// 00b111e6  e8b318e7ff           call 0x982a9e
// 00b111eb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b111e0();
extern int __stdcall G2_func_00b111e0(int);
int func_00b111e0()
{
    return G2_func_00b111e0(G1_func_00b111e0());
}
