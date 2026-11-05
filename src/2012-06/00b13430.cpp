// roc 2012-06 00b13430  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13430
//
// 00b13430  b9c005e200           mov ecx, 0xe205c0
// 00b13435  e916c5bcff           jmp 0x6df950
// auto-matched from its assembly shape

struct T_func_00b13430 { void m(); };
extern T_func_00b13430 G1_func_00b13430;
void func_00b13430()
{
    G1_func_00b13430.m();
}
