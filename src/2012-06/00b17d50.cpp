// roc 2012-06 00b17d50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17d50
//
// 00b17d50  b9a038e300           mov ecx, 0xe338a0
// 00b17d55  e9e67cd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b17d50 { void m(); };
extern T_func_00b17d50 G1_func_00b17d50;
void func_00b17d50()
{
    G1_func_00b17d50.m();
}
