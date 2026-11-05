// roc 2012-06 00b1f600  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f600
//
// 00b1f600  b97c2ae500           mov ecx, 0xe52a7c
// 00b1f605  e9e628a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1f600 { void m(); };
extern T_func_00b1f600 G1_func_00b1f600;
void func_00b1f600()
{
    G1_func_00b1f600.m();
}
