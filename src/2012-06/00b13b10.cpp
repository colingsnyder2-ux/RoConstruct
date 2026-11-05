// roc 2012-06 00b13b10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13b10
//
// 00b13b10  b99817e200           mov ecx, 0xe21798
// 00b13b15  e956be8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13b10 { void m(); };
extern T_func_00b13b10 G1_func_00b13b10;
void func_00b13b10()
{
    G1_func_00b13b10.m();
}
