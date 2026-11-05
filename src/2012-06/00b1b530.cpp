// roc 2012-06 00b1b530  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b530
//
// 00b1b530  b93087e400           mov ecx, 0xe48730
// 00b1b535  e966a8c5ff           jmp 0x775da0
// auto-matched from its assembly shape

struct T_func_00b1b530 { void m(); };
extern T_func_00b1b530 G1_func_00b1b530;
void func_00b1b530()
{
    G1_func_00b1b530.m();
}
