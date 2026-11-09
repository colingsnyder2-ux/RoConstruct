// roc 2012-06 00b10cd0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10cd0
//
// 00b10cd0  e8fbb6f0ff           call 0xa1c3d0
// 00b10cd5  50                   push eax
// 00b10cd6  e8c31de7ff           call 0x982a9e
// 00b10cdb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10cd0();
extern int __stdcall G2_func_00b10cd0(int);
int func_00b10cd0()
{
    return G2_func_00b10cd0(G1_func_00b10cd0());
}
