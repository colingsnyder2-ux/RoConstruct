// roc 2012-06 00b1af20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1af20
//
// 00b1af20  b9981ee400           mov ecx, 0xe41e98
// 00b1af25  e9464a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1af20 { void m(); };
extern T_func_00b1af20 G1_func_00b1af20;
void func_00b1af20()
{
    G1_func_00b1af20.m();
}
