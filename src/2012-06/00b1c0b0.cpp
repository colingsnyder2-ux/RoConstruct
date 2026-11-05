// roc 2012-06 00b1c0b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c0b0
//
// 00b1c0b0  b950a8e400           mov ecx, 0xe4a850
// 00b1c0b5  e9b650b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1c0b0 { void m(); };
extern T_func_00b1c0b0 G1_func_00b1c0b0;
void func_00b1c0b0()
{
    G1_func_00b1c0b0.m();
}
