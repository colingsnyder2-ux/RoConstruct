// roc 2012-06 00b1b440  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b440
//
// 00b1b440  b97489e400           mov ecx, 0xe48974
// 00b1b445  e966fec5ff           jmp 0x77b2b0
// auto-matched from its assembly shape

struct T_func_00b1b440 { void m(); };
extern T_func_00b1b440 G1_func_00b1b440;
void func_00b1b440()
{
    G1_func_00b1b440.m();
}
