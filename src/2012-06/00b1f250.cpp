// roc 2012-06 00b1f250  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f250
//
// 00b1f250  b94023e500           mov ecx, 0xe52340
// 00b1f255  e9e607d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1f250 { void m(); };
extern T_func_00b1f250 G1_func_00b1f250;
void func_00b1f250()
{
    G1_func_00b1f250.m();
}
