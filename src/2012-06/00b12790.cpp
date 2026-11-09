// roc 2012-06 00b12790  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12790
//
// 00b12790  b960a6e100           mov ecx, 0xe1a660
// 00b12795  e9063297ff           jmp 0x4859a0
// auto-matched from its assembly shape

struct T_func_00b12790 { void m(); };
extern T_func_00b12790 G1_func_00b12790;
void func_00b12790()
{
    G1_func_00b12790.m();
}
