// roc 2012-06 00b10080  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10080
//
// 00b10080  b95c6de500           mov ecx, 0xe56d5c
// 00b10085  e9765ceeff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00b10080 { void m(); };
extern T_func_00b10080 G1_func_00b10080;
void func_00b10080()
{
    G1_func_00b10080.m();
}
