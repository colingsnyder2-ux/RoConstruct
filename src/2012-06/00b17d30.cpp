// roc 2012-06 00b17d30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17d30
//
// 00b17d30  b91039e300           mov ecx, 0xe33910
// 00b17d35  e9b6a1a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b17d30 { void m(); };
extern T_func_00b17d30 G1_func_00b17d30;
void func_00b17d30()
{
    G1_func_00b17d30.m();
}
