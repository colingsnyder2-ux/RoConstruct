// roc 2012-06 00b175e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b175e0
//
// 00b175e0  b9201fe300           mov ecx, 0xe31f20
// 00b175e5  e986ebbfff           jmp 0x716170
// auto-matched from its assembly shape

struct T_func_00b175e0 { void m(); };
extern T_func_00b175e0 G1_func_00b175e0;
void func_00b175e0()
{
    G1_func_00b175e0.m();
}
