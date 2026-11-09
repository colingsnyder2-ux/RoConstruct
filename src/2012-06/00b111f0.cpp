// roc 2012-06 00b111f0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b111f0
//
// 00b111f0  e85b59f6ff           call 0xa76b50
// 00b111f5  50                   push eax
// 00b111f6  e8a318e7ff           call 0x982a9e
// 00b111fb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b111f0();
extern int __stdcall G2_func_00b111f0(int);
int func_00b111f0()
{
    return G2_func_00b111f0(G1_func_00b111f0());
}
