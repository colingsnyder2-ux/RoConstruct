// roc 2012-06 00b10570  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10570
//
// 00b10570  68c015b200           push 0xb215c0
// 00b10575  e87b2ce7ff           call 0x9831f5
// 00b1057a  59                   pop ecx
// 00b1057b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b10570;
extern void G1_func_00b10570(void*);
void func_00b10570()
{
    G1_func_00b10570(&G2_func_00b10570);
}
