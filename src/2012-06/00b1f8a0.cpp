// roc 2012-06 00b1f8a0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f8a0
//
// 00b1f8a0  c705d430e5002c3cb400 mov dword ptr [0xe530d4], 0xb43c2c
// 00b1f8aa  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b1f8a0;
extern char G2_func_00b1f8a0;
void func_00b1f8a0()
{
    G1_func_00b1f8a0 = &G2_func_00b1f8a0;
}
