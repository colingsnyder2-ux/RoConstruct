// roc 2012-06 00b1da60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1da60
//
// 00b1da60  b998f2e400           mov ecx, 0xe4f298
// 00b1da65  e936d2ccff           jmp 0x7eaca0
// auto-matched from its assembly shape

struct T_func_00b1da60 { void m(); };
extern T_func_00b1da60 G1_func_00b1da60;
void func_00b1da60()
{
    G1_func_00b1da60.m();
}
