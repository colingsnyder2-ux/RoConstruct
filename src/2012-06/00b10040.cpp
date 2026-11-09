// roc 2012-06 00b10040  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10040
//
// 00b10040  b95f6de500           mov ecx, 0xe56d5f
// 00b10045  e9b65ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10040 { void m(); };
extern T_func_00b10040 G1_func_00b10040;
void func_00b10040()
{
    G1_func_00b10040.m();
}
