// roc 2012-06 00b1dd70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1dd70
//
// 00b1dd70  b9c8f8e400           mov ecx, 0xe4f8c8
// 00b1dd75  e9d61bbcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b1dd70 { void m(); };
extern T_func_00b1dd70 G1_func_00b1dd70;
void func_00b1dd70()
{
    G1_func_00b1dd70.m();
}
