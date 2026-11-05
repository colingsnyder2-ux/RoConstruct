// roc 2012-06 00b1b450  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b450
//
// 00b1b450  b9008be400           mov ecx, 0xe48b00
// 00b1b455  e956f9c5ff           jmp 0x77adb0
// auto-matched from its assembly shape

struct T_func_00b1b450 { void m(); };
extern T_func_00b1b450 G1_func_00b1b450;
void func_00b1b450()
{
    G1_func_00b1b450.m();
}
