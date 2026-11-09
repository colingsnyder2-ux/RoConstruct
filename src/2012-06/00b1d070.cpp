// roc 2012-06 00b1d070  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d070
//
// 00b1d070  b920dee400           mov ecx, 0xe4de20
// 00b1d075  e9c629d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1d070 { void m(); };
extern T_func_00b1d070 G1_func_00b1d070;
void func_00b1d070()
{
    G1_func_00b1d070.m();
}
