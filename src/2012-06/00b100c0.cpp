// roc 2012-06 00b100c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b100c0
//
// 00b100c0  b9816de500           mov ecx, 0xe56d81
// 00b100c5  e9365ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b100c0 { void m(); };
extern T_func_00b100c0 G1_func_00b100c0;
void func_00b100c0()
{
    G1_func_00b100c0.m();
}
