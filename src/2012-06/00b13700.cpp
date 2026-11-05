// roc 2012-06 00b13700  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13700
//
// 00b13700  b9480ae200           mov ecx, 0xe20a48
// 00b13705  e966dab6ff           jmp 0x681170
// auto-matched from its assembly shape

struct T_func_00b13700 { void m(); };
extern T_func_00b13700 G1_func_00b13700;
void func_00b13700()
{
    G1_func_00b13700.m();
}
