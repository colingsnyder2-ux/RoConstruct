// roc 2012-06 00b11750  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11750
//
// 00b11750  b9c87ce100           mov ecx, 0xe17cc8
// 00b11755  e946fc8fff           jmp 0x4113a0
// auto-matched from its assembly shape

struct T_func_00b11750 { void m(); };
extern T_func_00b11750 G1_func_00b11750;
void func_00b11750()
{
    G1_func_00b11750.m();
}
