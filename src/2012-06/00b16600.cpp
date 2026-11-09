// roc 2012-06 00b16600  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16600
//
// 00b16600  c705ace2e2002c3cb400 mov dword ptr [0xe2e2ac], 0xb43c2c
// 00b1660a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b16600;
extern char G2_func_00b16600;
void func_00b16600()
{
    G1_func_00b16600 = &G2_func_00b16600;
}
