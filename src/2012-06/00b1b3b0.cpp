// roc 2012-06 00b1b3b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b3b0
//
// 00b1b3b0  b99088e400           mov ecx, 0xe48890
// 00b1b3b5  e9e629c6ff           jmp 0x77dda0
// auto-matched from its assembly shape

struct T_func_00b1b3b0 { void m(); };
extern T_func_00b1b3b0 G1_func_00b1b3b0;
void func_00b1b3b0()
{
    G1_func_00b1b3b0.m();
}
