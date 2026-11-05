// roc 2012-06 00b126e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b126e0
//
// 00b126e0  b94ca4e100           mov ecx, 0xe1a44c
// 00b126e5  e9266b96ff           jmp 0x479210
// auto-matched from its assembly shape

struct T_func_00b126e0 { void m(); };
extern T_func_00b126e0 G1_func_00b126e0;
void func_00b126e0()
{
    G1_func_00b126e0.m();
}
