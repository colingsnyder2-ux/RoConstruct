// roc 2012-06 00b10ca0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10ca0
//
// 00b10ca0  e8fb2ef0ff           call 0xa13ba0
// 00b10ca5  50                   push eax
// 00b10ca6  e8f31de7ff           call 0x982a9e
// 00b10cab  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10ca0();
extern int __stdcall G2_func_00b10ca0(int);
int func_00b10ca0()
{
    return G2_func_00b10ca0(G1_func_00b10ca0());
}
