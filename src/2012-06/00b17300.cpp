// roc 2012-06 00b17300  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17300
//
// 00b17300  c7054c13e3002c3cb400 mov dword ptr [0xe3134c], 0xb43c2c
// 00b1730a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b17300;
extern char G2_func_00b17300;
void func_00b17300()
{
    G1_func_00b17300 = &G2_func_00b17300;
}
