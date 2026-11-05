// roc 2012-06 00b21878  unit: seg_00b20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21878
//
// 00b21878  c705fca4e50054bbc200 mov dword ptr [0xe5a4fc], 0xc2bb54
// 00b21882  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b21878;
extern char G2_func_00b21878;
void func_00b21878()
{
    G1_func_00b21878 = &G2_func_00b21878;
}
