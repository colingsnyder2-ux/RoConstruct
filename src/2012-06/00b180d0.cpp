// roc 2012-06 00b180d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b180d0
//
// 00b180d0  b91842e300           mov ecx, 0xe34218
// 00b180d5  e9e6eac1ff           jmp 0x736bc0
// auto-matched from its assembly shape

struct T_func_00b180d0 { void m(); };
extern T_func_00b180d0 G1_func_00b180d0;
void func_00b180d0()
{
    G1_func_00b180d0.m();
}
