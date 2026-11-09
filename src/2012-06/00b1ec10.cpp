// roc 2012-06 00b1ec10  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ec10
//
// 00b1ec10  c7052414e5002c3cb400 mov dword ptr [0xe51424], 0xb43c2c
// 00b1ec1a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b1ec10;
extern char G2_func_00b1ec10;
void func_00b1ec10()
{
    G1_func_00b1ec10 = &G2_func_00b1ec10;
}
