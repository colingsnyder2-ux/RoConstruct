// roc 2012-06 00b1b3c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b3c0
//
// 00b1b3c0  b9088de400           mov ecx, 0xe48d08
// 00b1b3c5  e9d624c6ff           jmp 0x77d8a0
// auto-matched from its assembly shape

struct T_func_00b1b3c0 { void m(); };
extern T_func_00b1b3c0 G1_func_00b1b3c0;
void func_00b1b3c0()
{
    G1_func_00b1b3c0.m();
}
