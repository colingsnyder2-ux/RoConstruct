// roc 2012-06 00b1b150  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b150
//
// 00b1b150  b9e0dbe300           mov ecx, 0xe3dbe0
// 00b1b155  e916488fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b150 { void m(); };
extern T_func_00b1b150 G1_func_00b1b150;
void func_00b1b150()
{
    G1_func_00b1b150.m();
}
