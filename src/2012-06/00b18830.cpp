// roc 2012-06 00b18830  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18830
//
// 00b18830  b9b05ee300           mov ecx, 0xe35eb0
// 00b18835  e9b696a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18830 { void m(); };
extern T_func_00b18830 G1_func_00b18830;
void func_00b18830()
{
    G1_func_00b18830.m();
}
