// roc 2012-06 00b1bf50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bf50
//
// 00b1bf50  b9a0a4e400           mov ecx, 0xe4a4a0
// 00b1bf55  e9e695c4ff           jmp 0x765540
// auto-matched from its assembly shape

struct T_func_00b1bf50 { void m(); };
extern T_func_00b1bf50 G1_func_00b1bf50;
void func_00b1bf50()
{
    G1_func_00b1bf50.m();
}
