// roc 2012-06 00b1cdc0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cdc0
//
// 00b1cdc0  b920dae400           mov ecx, 0xe4da20
// 00b1cdc5  e9a643b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1cdc0 { void m(); };
extern T_func_00b1cdc0 G1_func_00b1cdc0;
void func_00b1cdc0()
{
    G1_func_00b1cdc0.m();
}
