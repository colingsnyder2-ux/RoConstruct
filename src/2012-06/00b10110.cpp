// roc 2012-06 00b10110  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10110
//
// 00b10110  b97d6de500           mov ecx, 0xe56d7d
// 00b10115  e9e65beeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10110 { void m(); };
extern T_func_00b10110 G1_func_00b10110;
void func_00b10110()
{
    G1_func_00b10110.m();
}
