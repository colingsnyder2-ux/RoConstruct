// roc 2012-06 00b1da50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1da50
//
// 00b1da50  b9f8ece400           mov ecx, 0xe4ecf8
// 00b1da55  e946d2ccff           jmp 0x7eaca0
// auto-matched from its assembly shape

struct T_func_00b1da50 { void m(); };
extern T_func_00b1da50 G1_func_00b1da50;
void func_00b1da50()
{
    G1_func_00b1da50.m();
}
