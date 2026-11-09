// roc 2012-06 00b1e7c0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e7c0
//
// 00b1e7c0  c705bc0fe5002c3cb400 mov dword ptr [0xe50fbc], 0xb43c2c
// 00b1e7ca  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b1e7c0;
extern char G2_func_00b1e7c0;
void func_00b1e7c0()
{
    G1_func_00b1e7c0 = &G2_func_00b1e7c0;
}
