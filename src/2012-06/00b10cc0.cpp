// roc 2012-06 00b10cc0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10cc0
//
// 00b10cc0  e8ab8cf0ff           call 0xa19970
// 00b10cc5  50                   push eax
// 00b10cc6  e8d31de7ff           call 0x982a9e
// 00b10ccb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10cc0();
extern int __stdcall G2_func_00b10cc0(int);
int func_00b10cc0()
{
    return G2_func_00b10cc0(G1_func_00b10cc0());
}
