// roc 2012-06 00b10100  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10100
//
// 00b10100  b97f6de500           mov ecx, 0xe56d7f
// 00b10105  e9f65beeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10100 { void m(); };
extern T_func_00b10100 G1_func_00b10100;
void func_00b10100()
{
    G1_func_00b10100.m();
}
