// roc 2012-06 00b1b700  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b700
//
// 00b1b700  b9308fe400           mov ecx, 0xe48f30
// 00b1b705  e9665ab6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b1b700 { void m(); };
extern T_func_00b1b700 G1_func_00b1b700;
void func_00b1b700()
{
    G1_func_00b1b700.m();
}
