// roc 2012-06 00aeeee0  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeeee0
//
// 00aeeee0  b91437e200           mov ecx, 0xe23714
// 00aeeee5  e9166ef0ff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00aeeee0 { void m(); };
extern T_func_00aeeee0 G1_func_00aeeee0;
void func_00aeeee0()
{
    G1_func_00aeeee0.m();
}
