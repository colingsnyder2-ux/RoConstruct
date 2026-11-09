// roc 2012-06 00b17260  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17260
//
// 00b17260  c7056c12e3002c3cb400 mov dword ptr [0xe3126c], 0xb43c2c
// 00b1726a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b17260;
extern char G2_func_00b17260;
void func_00b17260()
{
    G1_func_00b17260 = &G2_func_00b17260;
}
