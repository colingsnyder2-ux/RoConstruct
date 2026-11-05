// roc 2012-06 00b17290  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17290
//
// 00b17290  c705ec12e3002c3cb400 mov dword ptr [0xe312ec], 0xb43c2c
// 00b1729a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b17290;
extern char G2_func_00b17290;
void func_00b17290()
{
    G1_func_00b17290 = &G2_func_00b17290;
}
