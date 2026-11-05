// roc 2012-06 00b11730  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11730
//
// 00b11730  b9c07ce100           mov ecx, 0xe17cc0
// 00b11735  e9860490ff           jmp 0x411bc0
// auto-matched from its assembly shape

struct T_func_00b11730 { void m(); };
extern T_func_00b11730 G1_func_00b11730;
void func_00b11730()
{
    G1_func_00b11730.m();
}
