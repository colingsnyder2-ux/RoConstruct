// roc 2012-06 00b1be50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1be50
//
// 00b1be50  b9209ce400           mov ecx, 0xe49c20
// 00b1be55  e99660a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1be50 { void m(); };
extern T_func_00b1be50 G1_func_00b1be50;
void func_00b1be50()
{
    G1_func_00b1be50.m();
}
