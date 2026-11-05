// roc 2012-06 00b1f3f0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f3f0
//
// 00b1f3f0  c7056c27e5002c3cb400 mov dword ptr [0xe5276c], 0xb43c2c
// 00b1f3fa  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b1f3f0;
extern char G2_func_00b1f3f0;
void func_00b1f3f0()
{
    G1_func_00b1f3f0 = &G2_func_00b1f3f0;
}
