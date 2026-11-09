// roc 2012-06 00b21540  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21540
//
// 00b21540  b9b481e500           mov ecx, 0xe581b4
// 00b21545  e9c61abbff           jmp 0x6d3010
// auto-matched from its assembly shape

struct T_func_00b21540 { void m(); };
extern T_func_00b21540 G1_func_00b21540;
void func_00b21540()
{
    G1_func_00b21540.m();
}
