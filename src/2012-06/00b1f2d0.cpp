// roc 2012-06 00b1f2d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f2d0
//
// 00b1f2d0  b97022e500           mov ecx, 0xe52270
// 00b1f2d5  e96607d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1f2d0 { void m(); };
extern T_func_00b1f2d0 G1_func_00b1f2d0;
void func_00b1f2d0()
{
    G1_func_00b1f2d0.m();
}
