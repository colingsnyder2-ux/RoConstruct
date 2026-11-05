// roc 2012-06 00b202c0  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b202c0
//
// 00b202c0  b9684fe500           mov ecx, 0xe54f68
// 00b202c5  e9261ca7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b202c0 { void m(); };
extern T_func_00b202c0 G1_func_00b202c0;
void func_00b202c0()
{
    G1_func_00b202c0.m();
}
