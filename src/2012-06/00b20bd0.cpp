// roc 2012-06 00b20bd0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20bd0
//
// 00b20bd0  b9e85ee500           mov ecx, 0xe55ee8
// 00b20bd5  e99605b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b20bd0 { void m(); };
extern T_func_00b20bd0 G1_func_00b20bd0;
void func_00b20bd0()
{
    G1_func_00b20bd0.m();
}
