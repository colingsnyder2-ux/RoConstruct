// roc 2012-06 00b166c0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b166c0
//
// 00b166c0  c7052ce4e2002c3cb400 mov dword ptr [0xe2e42c], 0xb43c2c
// 00b166ca  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b166c0;
extern char G2_func_00b166c0;
void func_00b166c0()
{
    G1_func_00b166c0 = &G2_func_00b166c0;
}
