// roc 2012-06 00b1b430  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b430
//
// 00b1b430  b9388ae400           mov ecx, 0xe48a38
// 00b1b435  e94603c6ff           jmp 0x77b780
// auto-matched from its assembly shape

struct T_func_00b1b430 { void m(); };
extern T_func_00b1b430 G1_func_00b1b430;
void func_00b1b430()
{
    G1_func_00b1b430.m();
}
