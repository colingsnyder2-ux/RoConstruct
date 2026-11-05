// roc 2012-06 00b17d20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17d20
//
// 00b17d20  b9b039e300           mov ecx, 0xe339b0
// 00b17d25  e9267cbcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b17d20 { void m(); };
extern T_func_00b17d20 G1_func_00b17d20;
void func_00b17d20()
{
    G1_func_00b17d20.m();
}
