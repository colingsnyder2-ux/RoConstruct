// roc 2012-06 00b1b550  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b550
//
// 00b1b550  b99887e400           mov ecx, 0xe48798
// 00b1b555  e9a69ec5ff           jmp 0x775400
// auto-matched from its assembly shape

struct T_func_00b1b550 { void m(); };
extern T_func_00b1b550 G1_func_00b1b550;
void func_00b1b550()
{
    G1_func_00b1b550.m();
}
