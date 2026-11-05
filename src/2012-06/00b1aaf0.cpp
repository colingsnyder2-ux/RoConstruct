// roc 2012-06 00b1aaf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aaf0
//
// 00b1aaf0  b90086e300           mov ecx, 0xe38600
// 00b1aaf5  e9560ac5ff           jmp 0x76b550
// auto-matched from its assembly shape

struct T_func_00b1aaf0 { void m(); };
extern T_func_00b1aaf0 G1_func_00b1aaf0;
void func_00b1aaf0()
{
    G1_func_00b1aaf0.m();
}
