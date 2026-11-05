// roc 2012-06 00b15bc0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15bc0
//
// 00b15bc0  c705dcb5e2002c3cb400 mov dword ptr [0xe2b5dc], 0xb43c2c
// 00b15bca  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b15bc0;
extern char G2_func_00b15bc0;
void func_00b15bc0()
{
    G1_func_00b15bc0 = &G2_func_00b15bc0;
}
