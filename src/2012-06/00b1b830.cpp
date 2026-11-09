// roc 2012-06 00b1b830  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b830
//
// 00b1b830  b99893e400           mov ecx, 0xe49398
// 00b1b835  e9b666a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b830 { void m(); };
extern T_func_00b1b830 G1_func_00b1b830;
void func_00b1b830()
{
    G1_func_00b1b830.m();
}
