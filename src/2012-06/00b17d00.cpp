// roc 2012-06 00b17d00  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17d00
//
// 00b17d00  b9f039e300           mov ecx, 0xe339f0
// 00b17d05  e9e6a1a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17d00 { void m(); };
extern T_func_00b17d00 G1_func_00b17d00;
void func_00b17d00()
{
    G1_func_00b17d00.m();
}
