// roc 2012-06 00b18c30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18c30
//
// 00b18c30  b9bc73e300           mov ecx, 0xe373bc
// 00b18c35  e9b692a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b18c30 { void m(); };
extern T_func_00b18c30 G1_func_00b18c30;
void func_00b18c30()
{
    G1_func_00b18c30.m();
}
