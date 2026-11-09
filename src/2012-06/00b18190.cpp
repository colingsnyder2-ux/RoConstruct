// roc 2012-06 00b18190  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18190
//
// 00b18190  b9c84fe300           mov ecx, 0xe34fc8
// 00b18195  e9d6778fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b18190 { void m(); };
extern T_func_00b18190 G1_func_00b18190;
void func_00b18190()
{
    G1_func_00b18190.m();
}
