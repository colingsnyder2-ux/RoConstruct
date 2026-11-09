// roc 2012-06 00b1f270  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f270
//
// 00b1f270  b9181ee500           mov ecx, 0xe51e18
// 00b1f275  e9c607d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1f270 { void m(); };
extern T_func_00b1f270 G1_func_00b1f270;
void func_00b1f270()
{
    G1_func_00b1f270.m();
}
