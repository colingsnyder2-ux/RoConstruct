// roc 2012-06 00b16660  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16660
//
// 00b16660  c7056ce3e2002c3cb400 mov dword ptr [0xe2e36c], 0xb43c2c
// 00b1666a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b16660;
extern char G2_func_00b16660;
void func_00b16660()
{
    G1_func_00b16660 = &G2_func_00b16660;
}
