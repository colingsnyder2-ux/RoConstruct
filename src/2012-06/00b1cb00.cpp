// roc 2012-06 00b1cb00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1cb00
//
// 00b1cb00  b950d7e400           mov ecx, 0xe4d750
// 00b1cb05  e9e653a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1cb00 { void m(); };
extern T_func_00b1cb00 G1_func_00b1cb00;
void func_00b1cb00()
{
    G1_func_00b1cb00.m();
}
