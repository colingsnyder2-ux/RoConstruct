// roc 2012-06 00b11650  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11650
//
// 00b11650  b9d865e100           mov ecx, 0xe165d8
// 00b11655  e916e38fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b11650 { void m(); };
extern T_func_00b11650 G1_func_00b11650;
void func_00b11650()
{
    G1_func_00b11650.m();
}
