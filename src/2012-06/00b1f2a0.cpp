// roc 2012-06 00b1f2a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f2a0
//
// 00b1f2a0  b99020e500           mov ecx, 0xe52090
// 00b1f2a5  e99607d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1f2a0 { void m(); };
extern T_func_00b1f2a0 G1_func_00b1f2a0;
void func_00b1f2a0()
{
    G1_func_00b1f2a0.m();
}
