// roc 2012-06 00b1c060  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c060
//
// 00b1c060  b908a7e400           mov ecx, 0xe4a708
// 00b1c065  e90651b6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1c060 { void m(); };
extern T_func_00b1c060 G1_func_00b1c060;
void func_00b1c060()
{
    G1_func_00b1c060.m();
}
