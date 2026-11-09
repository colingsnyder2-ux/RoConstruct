// roc 2012-06 00b129e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b129e0
//
// 00b129e0  b998c2e100           mov ecx, 0xe1c298
// 00b129e5  e9d6b49aff           jmp 0x4bdec0
// auto-matched from its assembly shape

struct T_func_00b129e0 { void m(); };
extern T_func_00b129e0 G1_func_00b129e0;
void func_00b129e0()
{
    G1_func_00b129e0.m();
}
