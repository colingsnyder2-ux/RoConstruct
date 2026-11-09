// roc 2012-06 00b20610  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20610
//
// 00b20610  b93454e500           mov ecx, 0xe55434
// 00b20615  e9d618a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20610 { void m(); };
extern T_func_00b20610 G1_func_00b20610;
void func_00b20610()
{
    G1_func_00b20610.m();
}
