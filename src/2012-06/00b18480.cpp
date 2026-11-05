// roc 2012-06 00b18480  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18480
//
// 00b18480  c7051864e3002c3cb400 mov dword ptr [0xe36418], 0xb43c2c
// 00b1848a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b18480;
extern char G2_func_00b18480;
void func_00b18480()
{
    G1_func_00b18480 = &G2_func_00b18480;
}
