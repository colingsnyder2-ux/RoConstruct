// roc 2012-06 00b1aa30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aa30
//
// 00b1aa30  b9408ee300           mov ecx, 0xe38e40
// 00b1aa35  e96628c5ff           jmp 0x76d2a0
// auto-matched from its assembly shape

struct T_func_00b1aa30 { void m(); };
extern T_func_00b1aa30 G1_func_00b1aa30;
void func_00b1aa30()
{
    G1_func_00b1aa30.m();
}
