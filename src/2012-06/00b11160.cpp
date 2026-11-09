// roc 2012-06 00b11160  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11160
//
// 00b11160  e8abddf5ff           call 0xa6ef10
// 00b11165  50                   push eax
// 00b11166  e83319e7ff           call 0x982a9e
// 00b1116b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b11160();
extern int __stdcall G2_func_00b11160(int);
int func_00b11160()
{
    return G2_func_00b11160(G1_func_00b11160());
}
