// roc 2012-06 00b104a0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b104a0
//
// 00b104a0  e87be5e7ff           call 0x98ea20
// 00b104a5  50                   push eax
// 00b104a6  e8f325e7ff           call 0x982a9e
// 00b104ab  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b104a0();
extern int __stdcall G2_func_00b104a0(int);
int func_00b104a0()
{
    return G2_func_00b104a0(G1_func_00b104a0());
}
