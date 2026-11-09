// roc 2012-06 00b127e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b127e0
//
// 00b127e0  b92ca9e100           mov ecx, 0xe1a92c
// 00b127e5  e9366f98ff           jmp 0x499720
// auto-matched from its assembly shape

struct T_func_00b127e0 { void m(); };
extern T_func_00b127e0 G1_func_00b127e0;
void func_00b127e0()
{
    G1_func_00b127e0.m();
}
