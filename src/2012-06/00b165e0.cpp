// roc 2012-06 00b165e0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b165e0
//
// 00b165e0  c7056ce2e2002c3cb400 mov dword ptr [0xe2e26c], 0xb43c2c
// 00b165ea  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b165e0;
extern char G2_func_00b165e0;
void func_00b165e0()
{
    G1_func_00b165e0 = &G2_func_00b165e0;
}
