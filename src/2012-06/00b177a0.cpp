// roc 2012-06 00b177a0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b177a0
//
// 00b177a0  c7057425e3002c3cb400 mov dword ptr [0xe32574], 0xb43c2c
// 00b177aa  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b177a0;
extern char G2_func_00b177a0;
void func_00b177a0()
{
    G1_func_00b177a0 = &G2_func_00b177a0;
}
