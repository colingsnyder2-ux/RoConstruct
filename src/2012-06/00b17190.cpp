// roc 2012-06 00b17190  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17190
//
// 00b17190  b9400ae300           mov ecx, 0xe30a40
// 00b17195  e956ada7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17190 { void m(); };
extern T_func_00b17190 G1_func_00b17190;
void func_00b17190()
{
    G1_func_00b17190.m();
}
