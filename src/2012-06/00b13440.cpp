// roc 2012-06 00b13440  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13440
//
// 00b13440  b97011e200           mov ecx, 0xe21170
// 00b13445  e9f6c5d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13440 { void m(); };
extern T_func_00b13440 G1_func_00b13440;
void func_00b13440()
{
    G1_func_00b13440.m();
}
