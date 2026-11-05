// roc 2012-06 00b17d40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17d40
//
// 00b17d40  b90838e300           mov ecx, 0xe33808
// 00b17d45  e9a6a1a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17d40 { void m(); };
extern T_func_00b17d40 G1_func_00b17d40;
void func_00b17d40()
{
    G1_func_00b17d40.m();
}
