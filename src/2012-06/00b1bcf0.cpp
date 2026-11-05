// roc 2012-06 00b1bcf0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bcf0
//
// 00b1bcf0  b9b89ee400           mov ecx, 0xe49eb8
// 00b1bcf5  e9f661a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bcf0 { void m(); };
extern T_func_00b1bcf0 G1_func_00b1bcf0;
void func_00b1bcf0()
{
    G1_func_00b1bcf0.m();
}
