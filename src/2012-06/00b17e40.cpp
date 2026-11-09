// roc 2012-06 00b17e40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17e40
//
// 00b17e40  b9c03ee300           mov ecx, 0xe33ec0
// 00b17e45  e956c7c1ff           jmp 0x7345a0
// auto-matched from its assembly shape

struct T_func_00b17e40 { void m(); };
extern T_func_00b17e40 G1_func_00b17e40;
void func_00b17e40()
{
    G1_func_00b17e40.m();
}
