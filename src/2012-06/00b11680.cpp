// roc 2012-06 00b11680  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11680
//
// 00b11680  b90077e100           mov ecx, 0xe17700
// 00b11685  e9e6e28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b11680 { void m(); };
extern T_func_00b11680 G1_func_00b11680;
void func_00b11680()
{
    G1_func_00b11680.m();
}
