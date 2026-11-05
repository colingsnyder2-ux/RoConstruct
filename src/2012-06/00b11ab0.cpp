// roc 2012-06 00b11ab0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11ab0
//
// 00b11ab0  b94889e100           mov ecx, 0xe18948
// 00b11ab5  e9a6f292ff           jmp 0x440d60
// auto-matched from its assembly shape

struct T_func_00b11ab0 { void m(); };
extern T_func_00b11ab0 G1_func_00b11ab0;
void func_00b11ab0()
{
    G1_func_00b11ab0.m();
}
