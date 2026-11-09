// roc 2012-06 00b1ae70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ae70
//
// 00b1ae70  b99033e400           mov ecx, 0xe43390
// 00b1ae75  e9f64a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ae70 { void m(); };
extern T_func_00b1ae70 G1_func_00b1ae70;
void func_00b1ae70()
{
    G1_func_00b1ae70.m();
}
