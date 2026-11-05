// roc 2012-06 00b111a0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b111a0
//
// 00b111a0  e80b2cf6ff           call 0xa73db0
// 00b111a5  50                   push eax
// 00b111a6  e8f318e7ff           call 0x982a9e
// 00b111ab  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b111a0();
extern int __stdcall G2_func_00b111a0(int);
int func_00b111a0()
{
    return G2_func_00b111a0(G1_func_00b111a0());
}
