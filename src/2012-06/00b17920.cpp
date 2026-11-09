// roc 2012-06 00b17920  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17920
//
// 00b17920  b93023e300           mov ecx, 0xe32330
// 00b17925  e9c6f0c7ff           jmp 0x7969f0
// auto-matched from its assembly shape

struct T_func_00b17920 { void m(); };
extern T_func_00b17920 G1_func_00b17920;
void func_00b17920()
{
    G1_func_00b17920.m();
}
