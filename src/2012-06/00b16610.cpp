// roc 2012-06 00b16610  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16610
//
// 00b16610  c705cce2e2002c3cb400 mov dword ptr [0xe2e2cc], 0xb43c2c
// 00b1661a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b16610;
extern char G2_func_00b16610;
void func_00b16610()
{
    G1_func_00b16610 = &G2_func_00b16610;
}
