// roc 2012-06 00b189d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b189d0
//
// 00b189d0  b9106be300           mov ecx, 0xe36b10
// 00b189d5  e96670d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b189d0 { void m(); };
extern T_func_00b189d0 G1_func_00b189d0;
void func_00b189d0()
{
    G1_func_00b189d0.m();
}
