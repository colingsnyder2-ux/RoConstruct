// roc 2012-06 00b1afa0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1afa0
//
// 00b1afa0  b9580fe400           mov ecx, 0xe40f58
// 00b1afa5  e9c6498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1afa0 { void m(); };
extern T_func_00b1afa0 G1_func_00b1afa0;
void func_00b1afa0()
{
    G1_func_00b1afa0.m();
}
