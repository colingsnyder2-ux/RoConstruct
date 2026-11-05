// roc 2012-06 00b100a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b100a0
//
// 00b100a0  b9826de500           mov ecx, 0xe56d82
// 00b100a5  e9565ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b100a0 { void m(); };
extern T_func_00b100a0 G1_func_00b100a0;
void func_00b100a0()
{
    G1_func_00b100a0.m();
}
