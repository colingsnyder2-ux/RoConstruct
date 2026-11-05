// roc 2012-06 00b178b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b178b0
//
// 00b178b0  b9a023e300           mov ecx, 0xe323a0
// 00b178b5  e986b7c0ff           jmp 0x723040
// auto-matched from its assembly shape

struct T_func_00b178b0 { void m(); };
extern T_func_00b178b0 G1_func_00b178b0;
void func_00b178b0()
{
    G1_func_00b178b0.m();
}
