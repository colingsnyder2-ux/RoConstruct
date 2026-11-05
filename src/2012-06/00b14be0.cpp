// roc 2012-06 00b14be0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14be0
//
// 00b14be0  b97084e200           mov ecx, 0xe28470
// 00b14be5  e9e65cb1ff           jmp 0x62a8d0
// auto-matched from its assembly shape

struct T_func_00b14be0 { void m(); };
extern T_func_00b14be0 G1_func_00b14be0;
void func_00b14be0()
{
    G1_func_00b14be0.m();
}
