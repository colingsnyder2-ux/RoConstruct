// roc 2012-06 00b1f200  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f200
//
// 00b1f200  b9b021e500           mov ecx, 0xe521b0
// 00b1f205  e9665ed6ff           jmp 0x885070
// auto-matched from its assembly shape

struct T_func_00b1f200 { void m(); };
extern T_func_00b1f200 G1_func_00b1f200;
void func_00b1f200()
{
    G1_func_00b1f200.m();
}
