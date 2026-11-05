// roc 2012-06 00aeef30  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeef30
//
// 00aeef30  b91037e200           mov ecx, 0xe23710
// 00aeef35  e9c66df0ff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00aeef30 { void m(); };
extern T_func_00aeef30 G1_func_00aeef30;
void func_00aeef30()
{
    G1_func_00aeef30.m();
}
