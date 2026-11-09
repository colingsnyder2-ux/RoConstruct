// roc 2012-06 00b05630  unit: seg_00b00000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b05630
//
// 00b05630  6840e6e400           push 0xe4e640
// 00b05635  e806d6c3ff           call 0x742c40
// 00b0563a  59                   pop ecx
// 00b0563b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b05630;
extern void G1_func_00b05630(void*);
void func_00b05630()
{
    G1_func_00b05630(&G2_func_00b05630);
}
