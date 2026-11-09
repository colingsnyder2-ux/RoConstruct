// roc 2012-06 00b10000  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10000
//
// 00b10000  b9616de500           mov ecx, 0xe56d61
// 00b10005  e9f65ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10000 { void m(); };
extern T_func_00b10000 G1_func_00b10000;
void func_00b10000()
{
    G1_func_00b10000.m();
}
