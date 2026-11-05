// roc 2012-06 00b16620  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16620
//
// 00b16620  c705ece2e2002c3cb400 mov dword ptr [0xe2e2ec], 0xb43c2c
// 00b1662a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b16620;
extern char G2_func_00b16620;
void func_00b16620()
{
    G1_func_00b16620 = &G2_func_00b16620;
}
