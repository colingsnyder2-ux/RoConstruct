// roc 2012-06 00b128f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b128f0
//
// 00b128f0  b9b0bfe100           mov ecx, 0xe1bfb0
// 00b128f5  e976d08fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b128f0 { void m(); };
extern T_func_00b128f0 G1_func_00b128f0;
void func_00b128f0()
{
    G1_func_00b128f0.m();
}
