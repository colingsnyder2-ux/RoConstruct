// roc 2012-06 00b11bb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11bb0
//
// 00b11bb0  b91c8ae100           mov ecx, 0xe18a1c
// 00b11bb5  e916ae94ff           jmp 0x45c9d0
// auto-matched from its assembly shape

struct T_func_00b11bb0 { void m(); };
extern T_func_00b11bb0 G1_func_00b11bb0;
void func_00b11bb0()
{
    G1_func_00b11bb0.m();
}
