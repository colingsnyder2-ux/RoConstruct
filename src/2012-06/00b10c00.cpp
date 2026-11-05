// roc 2012-06 00b10c00  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10c00
//
// 00b10c00  e8db1aecff           call 0x9d26e0
// 00b10c05  50                   push eax
// 00b10c06  e8931ee7ff           call 0x982a9e
// 00b10c0b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10c00();
extern int __stdcall G2_func_00b10c00(int);
int func_00b10c00()
{
    return G2_func_00b10c00(G1_func_00b10c00());
}
