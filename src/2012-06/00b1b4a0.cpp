// roc 2012-06 00b1b4a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b4a0
//
// 00b1b4a0  b90c8de400           mov ecx, 0xe48d0c
// 00b1b4a5  e926e0c5ff           jmp 0x7794d0
// auto-matched from its assembly shape

struct T_func_00b1b4a0 { void m(); };
extern T_func_00b1b4a0 G1_func_00b1b4a0;
void func_00b1b4a0()
{
    G1_func_00b1b4a0.m();
}
