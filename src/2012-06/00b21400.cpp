// roc 2012-06 00b21400  unit: seg_00b20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21400
//
// 00b21400  c705746fe5008868b600 mov dword ptr [0xe56f74], 0xb66888
// 00b2140a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b21400;
extern char G2_func_00b21400;
void func_00b21400()
{
    G1_func_00b21400 = &G2_func_00b21400;
}
