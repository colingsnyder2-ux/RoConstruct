// roc 2012-06 00b161b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b161b0
//
// 00b161b0  b9c8d6e200           mov ecx, 0xe2d6c8
// 00b161b5  e98698d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b161b0 { void m(); };
extern T_func_00b161b0 G1_func_00b161b0;
void func_00b161b0()
{
    G1_func_00b161b0.m();
}
