// roc 2012-06 00b1aec0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aec0
//
// 00b1aec0  b9082ae400           mov ecx, 0xe42a08
// 00b1aec5  e9a64a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1aec0 { void m(); };
extern T_func_00b1aec0 G1_func_00b1aec0;
void func_00b1aec0()
{
    G1_func_00b1aec0.m();
}
