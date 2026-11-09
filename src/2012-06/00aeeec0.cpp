// roc 2012-06 00aeeec0  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeeec0
//
// 00aeeec0  b91537e200           mov ecx, 0xe23715
// 00aeeec5  e9366ef0ff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00aeeec0 { void m(); };
extern T_func_00aeeec0 G1_func_00aeeec0;
void func_00aeeec0()
{
    G1_func_00aeeec0.m();
}
