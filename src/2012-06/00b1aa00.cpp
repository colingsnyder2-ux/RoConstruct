// roc 2012-06 00b1aa00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aa00
//
// 00b1aa00  b95090e300           mov ecx, 0xe39050
// 00b1aa05  e97630c5ff           jmp 0x76da80
// auto-matched from its assembly shape

struct T_func_00b1aa00 { void m(); };
extern T_func_00b1aa00 G1_func_00b1aa00;
void func_00b1aa00()
{
    G1_func_00b1aa00.m();
}
