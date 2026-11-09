// roc 2012-06 00b188c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b188c0
//
// 00b188c0  b99061e300           mov ecx, 0xe36190
// 00b188c5  e92696a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b188c0 { void m(); };
extern T_func_00b188c0 G1_func_00b188c0;
void func_00b188c0()
{
    G1_func_00b188c0.m();
}
