// roc 2012-06 00b161d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b161d0
//
// 00b161d0  b990d5e200           mov ecx, 0xe2d590
// 00b161d5  e96698d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b161d0 { void m(); };
extern T_func_00b161d0 G1_func_00b161d0;
void func_00b161d0()
{
    G1_func_00b161d0.m();
}
