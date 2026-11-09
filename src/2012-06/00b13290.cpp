// roc 2012-06 00b13290  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13290
//
// 00b13290  b930f9e100           mov ecx, 0xe1f930
// 00b13295  e9d6c68fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13290 { void m(); };
extern T_func_00b13290 G1_func_00b13290;
void func_00b13290()
{
    G1_func_00b13290.m();
}
