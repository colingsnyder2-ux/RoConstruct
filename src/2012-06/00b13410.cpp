// roc 2012-06 00b13410  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13410
//
// 00b13410  b9b00be200           mov ecx, 0xe20bb0
// 00b13415  e936c5bcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b13410 { void m(); };
extern T_func_00b13410 G1_func_00b13410;
void func_00b13410()
{
    G1_func_00b13410.m();
}
