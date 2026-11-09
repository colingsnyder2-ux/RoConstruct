// roc 2012-06 00b13610  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13610
//
// 00b13610  b9600ce200           mov ecx, 0xe20c60
// 00b13615  e926c4d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13610 { void m(); };
extern T_func_00b13610 G1_func_00b13610;
void func_00b13610()
{
    G1_func_00b13610.m();
}
