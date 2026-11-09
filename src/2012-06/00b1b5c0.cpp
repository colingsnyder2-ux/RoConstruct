// roc 2012-06 00b1b5c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b5c0
//
// 00b1b5c0  b9c888e400           mov ecx, 0xe488c8
// 00b1b5c5  e9867cc5ff           jmp 0x773250
// auto-matched from its assembly shape

struct T_func_00b1b5c0 { void m(); };
extern T_func_00b1b5c0 G1_func_00b1b5c0;
void func_00b1b5c0()
{
    G1_func_00b1b5c0.m();
}
