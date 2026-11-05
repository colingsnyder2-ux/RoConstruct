// roc 2012-06 00b13620  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13620
//
// 00b13620  b97810e200           mov ecx, 0xe21078
// 00b13625  e926c3bcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b13620 { void m(); };
extern T_func_00b13620 G1_func_00b13620;
void func_00b13620()
{
    G1_func_00b13620.m();
}
