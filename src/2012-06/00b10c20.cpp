// roc 2012-06 00b10c20  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10c20
//
// 00b10c20  e86b1becff           call 0x9d2790
// 00b10c25  50                   push eax
// 00b10c26  e8731ee7ff           call 0x982a9e
// 00b10c2b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10c20();
extern int __stdcall G2_func_00b10c20(int);
int func_00b10c20()
{
    return G2_func_00b10c20(G1_func_00b10c20());
}
