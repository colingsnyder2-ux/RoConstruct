// roc 2012-06 00b165a0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b165a0
//
// 00b165a0  c705ece1e2002c3cb400 mov dword ptr [0xe2e1ec], 0xb43c2c
// 00b165aa  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b165a0;
extern char G2_func_00b165a0;
void func_00b165a0()
{
    G1_func_00b165a0 = &G2_func_00b165a0;
}
