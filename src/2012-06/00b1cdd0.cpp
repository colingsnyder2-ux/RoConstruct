// roc 2012-06 00b1cdd0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cdd0
//
// 00b1cdd0  b9b0d9e400           mov ecx, 0xe4d9b0
// 00b1cdd5  e9662cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1cdd0 { void m(); };
extern T_func_00b1cdd0 G1_func_00b1cdd0;
void func_00b1cdd0()
{
    G1_func_00b1cdd0.m();
}
