// roc 2012-06 00b12820  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12820
//
// 00b12820  b93ca9e100           mov ecx, 0xe1a93c
// 00b12825  e9b65b98ff           jmp 0x4983e0
// auto-matched from its assembly shape

struct T_func_00b12820 { void m(); };
extern T_func_00b12820 G1_func_00b12820;
void func_00b12820()
{
    G1_func_00b12820.m();
}
