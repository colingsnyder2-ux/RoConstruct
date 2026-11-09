// roc 2012-06 00b13420  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13420
//
// 00b13420  b96009e200           mov ecx, 0xe20960
// 00b13425  e916c6d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13420 { void m(); };
extern T_func_00b13420 G1_func_00b13420;
void func_00b13420()
{
    G1_func_00b13420.m();
}
