// roc 2012-06 00b18250  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18250
//
// 00b18250  b97054e300           mov ecx, 0xe35470
// 00b18255  e9969ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18250 { void m(); };
extern T_func_00b18250 G1_func_00b18250;
void func_00b18250()
{
    G1_func_00b18250.m();
}
