// roc 2012-06 00b13bc0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13bc0
//
// 00b13bc0  b99822e200           mov ecx, 0xe22298
// 00b13bc5  e926e3a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b13bc0 { void m(); };
extern T_func_00b13bc0 G1_func_00b13bc0;
void func_00b13bc0()
{
    G1_func_00b13bc0.m();
}
