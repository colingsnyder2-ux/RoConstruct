// roc 2012-06 00b1ed20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ed20
//
// 00b1ed20  b9f016e500           mov ecx, 0xe516f0
// 00b1ed25  e9a601d5ff           jmp 0x86eed0
// auto-matched from its assembly shape

struct T_func_00b1ed20 { void m(); };
extern T_func_00b1ed20 G1_func_00b1ed20;
void func_00b1ed20()
{
    G1_func_00b1ed20.m();
}
