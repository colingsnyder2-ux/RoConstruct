// roc 2012-06 00b1b4b0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b4b0
//
// 00b1b4b0  b9fc8ae400           mov ecx, 0xe48afc
// 00b1b4b5  e946dbc5ff           jmp 0x779000
// auto-matched from its assembly shape

struct T_func_00b1b4b0 { void m(); };
extern T_func_00b1b4b0 G1_func_00b1b4b0;
void func_00b1b4b0()
{
    G1_func_00b1b4b0.m();
}
