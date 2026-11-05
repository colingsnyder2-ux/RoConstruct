// roc 2012-06 00b1b5d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b5d0
//
// 00b1b5d0  b9148de400           mov ecx, 0xe48d14
// 00b1b5d5  e9a677c5ff           jmp 0x772d80
// auto-matched from its assembly shape

struct T_func_00b1b5d0 { void m(); };
extern T_func_00b1b5d0 G1_func_00b1b5d0;
void func_00b1b5d0()
{
    G1_func_00b1b5d0.m();
}
