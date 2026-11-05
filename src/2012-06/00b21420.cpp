// roc 2012-06 00b21420  unit: seg_00b20000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21420
//
// 00b21420  c705b46fe5008868b600 mov dword ptr [0xe56fb4], 0xb66888
// 00b2142a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern void* G1_func_00b21420;
extern char G2_func_00b21420;
void func_00b21420()
{
    G1_func_00b21420 = &G2_func_00b21420;
}
