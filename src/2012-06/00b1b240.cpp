// roc 2012-06 00b1b240  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b240
//
// 00b1b240  b948bfe300           mov ecx, 0xe3bf48
// 00b1b245  e926478fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b240 { void m(); };
extern T_func_00b1b240 G1_func_00b1b240;
void func_00b1b240()
{
    G1_func_00b1b240.m();
}
