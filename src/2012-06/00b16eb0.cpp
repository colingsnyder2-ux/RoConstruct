// roc 2012-06 00b16eb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16eb0
//
// 00b16eb0  b990f1e200           mov ecx, 0xe2f190
// 00b16eb5  e9868bd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b16eb0 { void m(); };
extern T_func_00b16eb0 G1_func_00b16eb0;
void func_00b16eb0()
{
    G1_func_00b16eb0.m();
}
