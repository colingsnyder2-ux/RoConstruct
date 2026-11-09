// roc 2012-06 00b172e0  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b172e0
//
// 00b172e0  c7050c13e3002c3cb400 mov dword ptr [0xe3130c], 0xb43c2c
// 00b172ea  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b172e0;
extern char G2_func_00b172e0;
void func_00b172e0()
{
    G1_func_00b172e0 = &G2_func_00b172e0;
}
