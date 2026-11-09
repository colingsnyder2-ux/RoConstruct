// roc 2012-06 00b1bd50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bd50
//
// 00b1bd50  b9b0a1e400           mov ecx, 0xe4a1b0
// 00b1bd55  e996acc7ff           jmp 0x7969f0
// auto-matched from its assembly shape

struct T_func_00b1bd50 { void m(); };
extern T_func_00b1bd50 G1_func_00b1bd50;
void func_00b1bd50()
{
    G1_func_00b1bd50.m();
}
