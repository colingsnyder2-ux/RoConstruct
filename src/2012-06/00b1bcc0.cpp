// roc 2012-06 00b1bcc0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bcc0
//
// 00b1bcc0  b9e89be400           mov ecx, 0xe49be8
// 00b1bcc5  e92662a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1bcc0 { void m(); };
extern T_func_00b1bcc0 G1_func_00b1bcc0;
void func_00b1bcc0()
{
    G1_func_00b1bcc0.m();
}
