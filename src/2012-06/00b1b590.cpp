// roc 2012-06 00b1b590  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b590
//
// 00b1b590  b9d089e400           mov ecx, 0xe489d0
// 00b1b595  e9268bc5ff           jmp 0x7740c0
// auto-matched from its assembly shape

struct T_func_00b1b590 { void m(); };
extern T_func_00b1b590 G1_func_00b1b590;
void func_00b1b590()
{
    G1_func_00b1b590.m();
}
