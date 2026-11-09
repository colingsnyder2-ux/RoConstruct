// roc 2012-06 00b21410  unit: seg_00b20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21410
//
// 00b21410  c705886fe500984bb700 mov dword ptr [0xe56f88], 0xb74b98
// 00b2141a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b21410;
extern char G2_func_00b21410;
void func_00b21410()
{
    G1_func_00b21410 = &G2_func_00b21410;
}
