// roc 2012-06 00b13b60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13b60
//
// 00b13b60  b9a020e200           mov ecx, 0xe220a0
// 00b13b65  e9f652a3ff           jmp 0x548e60
// auto-matched from its assembly shape

struct T_func_00b13b60 { void m(); };
extern T_func_00b13b60 G1_func_00b13b60;
void func_00b13b60()
{
    G1_func_00b13b60.m();
}
