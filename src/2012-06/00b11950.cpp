// roc 2012-06 00b11950  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11950
//
// 00b11950  b9f082e100           mov ecx, 0xe182f0
// 00b11955  e916e08fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b11950 { void m(); };
extern T_func_00b11950 G1_func_00b11950;
void func_00b11950()
{
    G1_func_00b11950.m();
}
