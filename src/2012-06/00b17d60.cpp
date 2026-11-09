// roc 2012-06 00b17d60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17d60
//
// 00b17d60  b9e038e300           mov ecx, 0xe338e0
// 00b17d65  e986a1a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17d60 { void m(); };
extern T_func_00b17d60 G1_func_00b17d60;
void func_00b17d60()
{
    G1_func_00b17d60.m();
}
