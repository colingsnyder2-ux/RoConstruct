// roc 2012-06 00b11790  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11790
//
// 00b11790  b9d87ce100           mov ecx, 0xe17cd8
// 00b11795  e936eb8fff           jmp 0x4102d0
// auto-matched from its assembly shape

struct T_func_00b11790 { void m(); };
extern T_func_00b11790 G1_func_00b11790;
void func_00b11790()
{
    G1_func_00b11790.m();
}
