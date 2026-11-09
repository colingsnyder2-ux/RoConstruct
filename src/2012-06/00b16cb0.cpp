// roc 2012-06 00b16cb0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16cb0
//
// 00b16cb0  b938fae200           mov ecx, 0xe2fa38
// 00b16cb5  e9362abcff           jmp 0x6d96f0
// auto-matched from its assembly shape

struct T_func_00b16cb0 { void m(); };
extern T_func_00b16cb0 G1_func_00b16cb0;
void func_00b16cb0()
{
    G1_func_00b16cb0.m();
}
