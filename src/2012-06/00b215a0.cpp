// roc 2012-06 00b215a0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b215a0
//
// 00b215a0  b94093e500           mov ecx, 0xe59340
// 00b215a5  e9f6c1e7ff           jmp 0x99d7a0
// auto-matched from its assembly shape

struct T_func_00b215a0 { void m(); };
extern T_func_00b215a0 G1_func_00b215a0;
void func_00b215a0()
{
    G1_func_00b215a0.m();
}
