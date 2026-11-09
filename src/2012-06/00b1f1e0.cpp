// roc 2012-06 00b1f1e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f1e0
//
// 00b1f1e0  b93022e500           mov ecx, 0xe52230
// 00b1f1e5  e95608d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1f1e0 { void m(); };
extern T_func_00b1f1e0 G1_func_00b1f1e0;
void func_00b1f1e0()
{
    G1_func_00b1f1e0.m();
}
