// roc 2012-06 00b131d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b131d0
//
// 00b131d0  b978e3e100           mov ecx, 0xe1e378
// 00b131d5  e906ffa0ff           jmp 0x5230e0
// auto-matched from its assembly shape

struct T_func_00b131d0 { void m(); };
extern T_func_00b131d0 G1_func_00b131d0;
void func_00b131d0()
{
    G1_func_00b131d0.m();
}
