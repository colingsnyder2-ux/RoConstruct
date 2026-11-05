// roc 2012-06 00b12ea0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12ea0
//
// 00b12ea0  c705a8e1e1002c3cb400 mov dword ptr [0xe1e1a8], 0xb43c2c
// 00b12eaa  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b12ea0;
extern char G2_func_00b12ea0;
void func_00b12ea0()
{
    G1_func_00b12ea0 = &G2_func_00b12ea0;
}
