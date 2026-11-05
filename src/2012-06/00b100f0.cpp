// roc 2012-06 00b100f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b100f0
//
// 00b100f0  b9836de500           mov ecx, 0xe56d83
// 00b100f5  e9065ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b100f0 { void m(); };
extern T_func_00b100f0 G1_func_00b100f0;
void func_00b100f0()
{
    G1_func_00b100f0.m();
}
