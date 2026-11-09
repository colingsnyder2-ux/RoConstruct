// roc 2012-06 00b1aba0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aba0
//
// 00b1aba0  b9707ee300           mov ecx, 0xe37e70
// 00b1aba5  e9b6efc4ff           jmp 0x769b60
// auto-matched from its assembly shape

struct T_func_00b1aba0 { void m(); };
extern T_func_00b1aba0 G1_func_00b1aba0;
void func_00b1aba0()
{
    G1_func_00b1aba0.m();
}
