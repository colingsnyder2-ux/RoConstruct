// roc 2012-06 00b10cf0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10cf0
//
// 00b10cf0  e83bd6f0ff           call 0xa1e330
// 00b10cf5  50                   push eax
// 00b10cf6  e8a31de7ff           call 0x982a9e
// 00b10cfb  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10cf0();
extern int __stdcall G2_func_00b10cf0(int);
int func_00b10cf0()
{
    return G2_func_00b10cf0(G1_func_00b10cf0());
}
