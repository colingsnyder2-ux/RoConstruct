// roc 2012-06 00b10010  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10010
//
// 00b10010  b95d6de500           mov ecx, 0xe56d5d
// 00b10015  e9e65ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10010 { void m(); };
extern T_func_00b10010 G1_func_00b10010;
void func_00b10010()
{
    G1_func_00b10010.m();
}
