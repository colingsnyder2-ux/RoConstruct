// roc 2012-06 00b10cb0  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10cb0
//
// 00b10cb0  68d017b200           push 0xb217d0
// 00b10cb5  e83b25e7ff           call 0x9831f5
// 00b10cba  59                   pop ecx
// 00b10cbb  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b10cb0;
extern void G1_func_00b10cb0(void*);
void func_00b10cb0()
{
    G1_func_00b10cb0(&G2_func_00b10cb0);
}
