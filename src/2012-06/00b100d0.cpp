// roc 2012-06 00b100d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b100d0
//
// 00b100d0  b97e6de500           mov ecx, 0xe56d7e
// 00b100d5  e9265ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b100d0 { void m(); };
extern T_func_00b100d0 G1_func_00b100d0;
void func_00b100d0()
{
    G1_func_00b100d0.m();
}
