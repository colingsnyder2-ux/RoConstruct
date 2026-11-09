// roc 2012-06 00b1b460  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b460
//
// 00b1b460  b9d48ae400           mov ecx, 0xe48ad4
// 00b1b465  e9c6f3c5ff           jmp 0x77a830
// auto-matched from its assembly shape

struct T_func_00b1b460 { void m(); };
extern T_func_00b1b460 G1_func_00b1b460;
void func_00b1b460()
{
    G1_func_00b1b460.m();
}
