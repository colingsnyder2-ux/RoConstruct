// roc 2012-06 00b17250  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17250
//
// 00b17250  c7058c12e3002c3cb400 mov dword ptr [0xe3128c], 0xb43c2c
// 00b1725a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b17250;
extern char G2_func_00b17250;
void func_00b17250()
{
    G1_func_00b17250 = &G2_func_00b17250;
}
