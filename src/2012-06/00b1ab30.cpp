// roc 2012-06 00b1ab30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ab30
//
// 00b1ab30  b94083e300           mov ecx, 0xe38340
// 00b1ab35  e91612b6ff           jmp 0x67bd50
// auto-matched from its assembly shape

struct T_func_00b1ab30 { void m(); };
extern T_func_00b1ab30 G1_func_00b1ab30;
void func_00b1ab30()
{
    G1_func_00b1ab30.m();
}
