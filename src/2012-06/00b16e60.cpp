// roc 2012-06 00b16e60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16e60
//
// 00b16e60  b9f000e300           mov ecx, 0xe300f0
// 00b16e65  e9c680bcff           jmp 0x6def30
// auto-matched from its assembly shape

struct T_func_00b16e60 { void m(); };
extern T_func_00b16e60 G1_func_00b16e60;
void func_00b16e60()
{
    G1_func_00b16e60.m();
}
