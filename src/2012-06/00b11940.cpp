// roc 2012-06 00b11940  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11940
//
// 00b11940  b9d884e100           mov ecx, 0xe184d8
// 00b11945  e926e08fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b11940 { void m(); };
extern T_func_00b11940 G1_func_00b11940;
void func_00b11940()
{
    G1_func_00b11940.m();
}
