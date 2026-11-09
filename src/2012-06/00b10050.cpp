// roc 2012-06 00b10050  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10050
//
// 00b10050  b95b6de500           mov ecx, 0xe56d5b
// 00b10055  e9a65ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10050 { void m(); };
extern T_func_00b10050 G1_func_00b10050;
void func_00b10050()
{
    G1_func_00b10050.m();
}
