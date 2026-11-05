// roc 2012-06 00aedfc0  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aedfc0
//
// 00aedfc0  b99824e200           mov ecx, 0xe22498
// 00aedfc5  e9663aa7ff           jmp 0x561a30
// auto-matched from its assembly shape

struct T_func_00aedfc0 { void m(); };
extern T_func_00aedfc0 G1_func_00aedfc0;
void func_00aedfc0()
{
    G1_func_00aedfc0.m();
}
