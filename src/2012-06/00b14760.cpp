// roc 2012-06 00b14760  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14760
//
// 00b14760  b9f84de200           mov ecx, 0xe24df8
// 00b14765  e986d7a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b14760 { void m(); };
extern T_func_00b14760 G1_func_00b14760;
void func_00b14760()
{
    G1_func_00b14760.m();
}
