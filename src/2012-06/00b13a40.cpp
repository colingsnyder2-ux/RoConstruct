// roc 2012-06 00b13a40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13a40
//
// 00b13a40  b91822e200           mov ecx, 0xe22218
// 00b13a45  e9f6bfd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b13a40 { void m(); };
extern T_func_00b13a40 G1_func_00b13a40;
void func_00b13a40()
{
    G1_func_00b13a40.m();
}
