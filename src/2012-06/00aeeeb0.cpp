// roc 2012-06 00aeeeb0  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeeeb0
//
// 00aeeeb0  b91337e200           mov ecx, 0xe23713
// 00aeeeb5  e9466ef0ff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00aeeeb0 { void m(); };
extern T_func_00aeeeb0 G1_func_00aeeeb0;
void func_00aeeeb0()
{
    G1_func_00aeeeb0.m();
}
