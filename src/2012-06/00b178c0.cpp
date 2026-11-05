// roc 2012-06 00b178c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b178c0
//
// 00b178c0  b91822e300           mov ecx, 0xe32218
// 00b178c5  e9c6b6c0ff           jmp 0x722f90
// auto-matched from its assembly shape

struct T_func_00b178c0 { void m(); };
extern T_func_00b178c0 G1_func_00b178c0;
void func_00b178c0()
{
    G1_func_00b178c0.m();
}
