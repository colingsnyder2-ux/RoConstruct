// roc 2012-06 00b1cde0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cde0
//
// 00b1cde0  b9f0d8e400           mov ecx, 0xe4d8f0
// 00b1cde5  e9562cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1cde0 { void m(); };
extern T_func_00b1cde0 G1_func_00b1cde0;
void func_00b1cde0()
{
    G1_func_00b1cde0.m();
}
