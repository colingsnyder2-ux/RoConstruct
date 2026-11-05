// roc 2012-06 00b1ad50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ad50
//
// 00b1ad50  b9e055e400           mov ecx, 0xe455e0
// 00b1ad55  e9164c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ad50 { void m(); };
extern T_func_00b1ad50 G1_func_00b1ad50;
void func_00b1ad50()
{
    G1_func_00b1ad50.m();
}
