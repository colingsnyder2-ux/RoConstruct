// roc 2012-06 00b131f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b131f0
//
// 00b131f0  b918e2e100           mov ecx, 0xe1e218
// 00b131f5  e9f609a1ff           jmp 0x523bf0
// auto-matched from its assembly shape

struct T_func_00b131f0 { void m(); };
extern T_func_00b131f0 G1_func_00b131f0;
void func_00b131f0()
{
    G1_func_00b131f0.m();
}
