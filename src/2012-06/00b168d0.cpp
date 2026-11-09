// roc 2012-06 00b168d0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b168d0
//
// 00b168d0  c705fce7e2002c3cb400 mov dword ptr [0xe2e7fc], 0xb43c2c
// 00b168da  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b168d0;
extern char G2_func_00b168d0;
void func_00b168d0()
{
    G1_func_00b168d0 = &G2_func_00b168d0;
}
