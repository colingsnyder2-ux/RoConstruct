// roc 2012-06 00b1e810  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e810
//
// 00b1e810  c705640ce5002c3cb400 mov dword ptr [0xe50c64], 0xb43c2c
// 00b1e81a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b1e810;
extern char G2_func_00b1e810;
void func_00b1e810()
{
    G1_func_00b1e810 = &G2_func_00b1e810;
}
