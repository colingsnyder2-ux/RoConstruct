// roc 2012-06 00b1f280  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f280
//
// 00b1f280  b93024e500           mov ecx, 0xe52430
// 00b1f285  e9b607d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1f280 { void m(); };
extern T_func_00b1f280 G1_func_00b1f280;
void func_00b1f280()
{
    G1_func_00b1f280.m();
}
