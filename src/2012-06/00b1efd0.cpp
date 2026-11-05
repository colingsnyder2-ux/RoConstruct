// roc 2012-06 00b1efd0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1efd0
//
// 00b1efd0  b9f01ce500           mov ecx, 0xe51cf0
// 00b1efd5  e916b0b8ff           jmp 0x6a9ff0
// auto-matched from its assembly shape

struct T_func_00b1efd0 { void m(); };
extern T_func_00b1efd0 G1_func_00b1efd0;
void func_00b1efd0()
{
    G1_func_00b1efd0.m();
}
