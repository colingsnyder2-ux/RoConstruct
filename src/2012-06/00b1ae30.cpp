// roc 2012-06 00b1ae30  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ae30
//
// 00b1ae30  b9303be400           mov ecx, 0xe43b30
// 00b1ae35  e9364b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ae30 { void m(); };
extern T_func_00b1ae30 G1_func_00b1ae30;
void func_00b1ae30()
{
    G1_func_00b1ae30.m();
}
