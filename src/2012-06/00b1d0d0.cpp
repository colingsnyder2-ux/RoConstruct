// roc 2012-06 00b1d0d0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d0d0
//
// 00b1d0d0  c705e406dd00984bb700 mov dword ptr [0xdd06e4], 0xb74b98
// 00b1d0da  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b1d0d0;
extern char G2_func_00b1d0d0;
void func_00b1d0d0()
{
    G1_func_00b1d0d0 = &G2_func_00b1d0d0;
}
