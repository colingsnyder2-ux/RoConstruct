// roc 2012-06 00b16590  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16590
//
// 00b16590  c705cce1e2002c3cb400 mov dword ptr [0xe2e1cc], 0xb43c2c
// 00b1659a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b16590;
extern char G2_func_00b16590;
void func_00b16590()
{
    G1_func_00b16590 = &G2_func_00b16590;
}
