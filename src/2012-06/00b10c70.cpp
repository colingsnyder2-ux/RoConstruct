// roc 2012-06 00b10c70  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10c70
//
// 00b10c70  68b017b200           push 0xb217b0
// 00b10c75  e87b25e7ff           call 0x9831f5
// 00b10c7a  59                   pop ecx
// 00b10c7b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b10c70;
extern void G1_func_00b10c70(void*);
void func_00b10c70()
{
    G1_func_00b10c70(&G2_func_00b10c70);
}
