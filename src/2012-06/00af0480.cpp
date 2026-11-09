// roc 2012-06 00af0480  unit: seg_00af0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00af0480
//
// 00af0480  b99452e200           mov ecx, 0xe25294
// 00af0485  e9a615a7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00af0480 { void m(); };
extern T_func_00af0480 G1_func_00af0480;
void func_00af0480()
{
    G1_func_00af0480.m();
}
