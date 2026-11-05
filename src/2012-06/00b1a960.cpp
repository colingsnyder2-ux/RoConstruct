// roc 2012-06 00b1a960  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a960
//
// 00b1a960  b93097e300           mov ecx, 0xe39730
// 00b1a965  e92648c5ff           jmp 0x76f190
// auto-matched from its assembly shape

struct T_func_00b1a960 { void m(); };
extern T_func_00b1a960 G1_func_00b1a960;
void func_00b1a960()
{
    G1_func_00b1a960.m();
}
