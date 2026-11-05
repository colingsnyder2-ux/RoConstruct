// roc 2012-06 00b21430  unit: seg_00b20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21430
//
// 00b21430  c705c86fe500984bb700 mov dword ptr [0xe56fc8], 0xb74b98
// 00b2143a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b21430;
extern char G2_func_00b21430;
void func_00b21430()
{
    G1_func_00b21430 = &G2_func_00b21430;
}
