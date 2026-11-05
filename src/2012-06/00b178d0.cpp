// roc 2012-06 00b178d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b178d0
//
// 00b178d0  b9b024e300           mov ecx, 0xe324b0
// 00b178d5  e916b8c0ff           jmp 0x7230f0
// auto-matched from its assembly shape

struct T_func_00b178d0 { void m(); };
extern T_func_00b178d0 G1_func_00b178d0;
void func_00b178d0()
{
    G1_func_00b178d0.m();
}
