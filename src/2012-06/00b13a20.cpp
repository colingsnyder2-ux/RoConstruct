// roc 2012-06 00b13a20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13a20
//
// 00b13a20  b96825e200           mov ecx, 0xe22568
// 00b13a25  e916c0d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13a20 { void m(); };
extern T_func_00b13a20 G1_func_00b13a20;
void func_00b13a20()
{
    G1_func_00b13a20.m();
}
