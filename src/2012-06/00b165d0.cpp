// roc 2012-06 00b165d0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b165d0
//
// 00b165d0  c7054ce2e2002c3cb400 mov dword ptr [0xe2e24c], 0xb43c2c
// 00b165da  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b165d0;
extern char G2_func_00b165d0;
void func_00b165d0()
{
    G1_func_00b165d0 = &G2_func_00b165d0;
}
