// roc 2012-06 00b1f620  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f620
//
// 00b1f620  b9042be500           mov ecx, 0xe52b04
// 00b1f625  e9c628a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f620 { void m(); };
extern T_func_00b1f620 G1_func_00b1f620;
void func_00b1f620()
{
    G1_func_00b1f620.m();
}
