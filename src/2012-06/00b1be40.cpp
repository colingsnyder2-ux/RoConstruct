// roc 2012-06 00b1be40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1be40
//
// 00b1be40  b9b099e400           mov ecx, 0xe499b0
// 00b1be45  e9a660a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1be40 { void m(); };
extern T_func_00b1be40 G1_func_00b1be40;
void func_00b1be40()
{
    G1_func_00b1be40.m();
}
