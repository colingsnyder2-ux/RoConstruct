// roc 2012-06 00b1be20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1be20
//
// 00b1be20  b9a89be400           mov ecx, 0xe49ba8
// 00b1be25  e9c6abc7ff           jmp 0x7969f0
// auto-matched from its assembly shape

struct T_func_00b1be20 { void m(); };
extern T_func_00b1be20 G1_func_00b1be20;
void func_00b1be20()
{
    G1_func_00b1be20.m();
}
