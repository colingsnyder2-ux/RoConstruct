// roc 2012-06 00b20250  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20250
//
// 00b20250  b9b841e500           mov ecx, 0xe541b8
// 00b20255  e916f78eff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b20250 { void m(); };
extern T_func_00b20250 G1_func_00b20250;
void func_00b20250()
{
    G1_func_00b20250.m();
}
