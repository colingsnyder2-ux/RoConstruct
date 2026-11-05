// roc 2012-06 00b14b10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14b10
//
// 00b14b10  b9c079e200           mov ecx, 0xe279c0
// 00b14b15  e956ae8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b14b10 { void m(); };
extern T_func_00b14b10 G1_func_00b14b10;
void func_00b14b10()
{
    G1_func_00b14b10.m();
}
