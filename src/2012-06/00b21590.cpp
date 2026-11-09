// roc 2012-06 00b21590  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21590
//
// 00b21590  b91c93e500           mov ecx, 0xe5931c
// 00b21595  e9a6feecff           jmp 0x9f1440
// auto-matched from its assembly shape

struct T_func_00b21590 { void m(); };
extern T_func_00b21590 G1_func_00b21590;
void func_00b21590()
{
    G1_func_00b21590.m();
}
