// roc 2012-06 00b114a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b114a0
//
// 00b114a0  b91c64e100           mov ecx, 0xe1641c
// 00b114a5  e926268fff           jmp 0x403ad0
// auto-matched from its assembly shape

struct T_func_00b114a0 { void m(); };
extern T_func_00b114a0 G1_func_00b114a0;
void func_00b114a0()
{
    G1_func_00b114a0.m();
}
