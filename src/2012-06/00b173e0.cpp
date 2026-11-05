// roc 2012-06 00b173e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b173e0
//
// 00b173e0  b9b813e300           mov ecx, 0xe313b8
// 00b173e5  e95659bfff           jmp 0x70cd40
// auto-matched from its assembly shape

struct T_func_00b173e0 { void m(); };
extern T_func_00b173e0 G1_func_00b173e0;
void func_00b173e0()
{
    G1_func_00b173e0.m();
}
