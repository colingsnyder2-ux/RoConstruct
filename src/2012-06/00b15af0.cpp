// roc 2012-06 00b15af0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15af0
//
// 00b15af0  b980a9e200           mov ecx, 0xe2a980
// 00b15af5  e93639b7ff           jmp 0x689430
// auto-matched from its assembly shape

struct T_func_00b15af0 { void m(); };
extern T_func_00b15af0 G1_func_00b15af0;
void func_00b15af0()
{
    G1_func_00b15af0.m();
}
