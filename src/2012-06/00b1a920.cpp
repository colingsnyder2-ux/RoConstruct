// roc 2012-06 00b1a920  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1a920
//
// 00b1a920  b9f099e300           mov ecx, 0xe399f0
// 00b1a925  e93651c5ff           jmp 0x76fa60
// auto-matched from its assembly shape

struct T_func_00b1a920 { void m(); };
extern T_func_00b1a920 G1_func_00b1a920;
void func_00b1a920()
{
    G1_func_00b1a920.m();
}
