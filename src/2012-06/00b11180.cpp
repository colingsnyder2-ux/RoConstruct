// roc 2012-06 00b11180  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11180
//
// 00b11180  e86beff5ff           call 0xa700f0
// 00b11185  50                   push eax
// 00b11186  e81319e7ff           call 0x982a9e
// 00b1118b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b11180();
extern int __stdcall G2_func_00b11180(int);
int func_00b11180()
{
    return G2_func_00b11180(G1_func_00b11180());
}
