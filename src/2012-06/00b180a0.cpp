// roc 2012-06 00b180a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b180a0
//
// 00b180a0  b92844e300           mov ecx, 0xe34428
// 00b180a5  e9b6f3c1ff           jmp 0x737460
// auto-matched from its assembly shape

struct T_func_00b180a0 { void m(); };
extern T_func_00b180a0 G1_func_00b180a0;
void func_00b180a0()
{
    G1_func_00b180a0.m();
}
