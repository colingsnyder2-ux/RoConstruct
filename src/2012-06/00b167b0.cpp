// roc 2012-06 00b167b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b167b0
//
// 00b167b0  b9e8e4e200           mov ecx, 0xe2e4e8
// 00b167b5  e9b6918fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b167b0 { void m(); };
extern T_func_00b167b0 G1_func_00b167b0;
void func_00b167b0()
{
    G1_func_00b167b0.m();
}
