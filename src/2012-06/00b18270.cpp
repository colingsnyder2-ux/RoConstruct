// roc 2012-06 00b18270  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18270
//
// 00b18270  b93849db00           mov ecx, 0xdb4938
// 00b18275  e9c6b2c2ff           jmp 0x743540
// auto-matched from its assembly shape

struct T_func_00b18270 { void m(); };
extern T_func_00b18270 G1_func_00b18270;
void func_00b18270()
{
    G1_func_00b18270.m();
}
