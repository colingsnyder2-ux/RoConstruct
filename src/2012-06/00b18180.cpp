// roc 2012-06 00b18180  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18180
//
// 00b18180  b9b051e300           mov ecx, 0xe351b0
// 00b18185  e9e6778fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b18180 { void m(); };
extern T_func_00b18180 G1_func_00b18180;
void func_00b18180()
{
    G1_func_00b18180.m();
}
