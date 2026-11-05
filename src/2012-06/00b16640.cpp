// roc 2012-06 00b16640  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16640
//
// 00b16640  c7052ce3e2002c3cb400 mov dword ptr [0xe2e32c], 0xb43c2c
// 00b1664a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b16640;
extern char G2_func_00b16640;
void func_00b16640()
{
    G1_func_00b16640 = &G2_func_00b16640;
}
