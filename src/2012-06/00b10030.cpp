// roc 2012-06 00b10030  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10030
//
// 00b10030  b9626de500           mov ecx, 0xe56d62
// 00b10035  e9c65ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10030 { void m(); };
extern T_func_00b10030 G1_func_00b10030;
void func_00b10030()
{
    G1_func_00b10030.m();
}
