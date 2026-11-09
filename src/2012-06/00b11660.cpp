// roc 2012-06 00b11660  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11660
//
// 00b11660  b9d07ae100           mov ecx, 0xe17ad0
// 00b11665  e906e38fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b11660 { void m(); };
extern T_func_00b11660 G1_func_00b11660;
void func_00b11660()
{
    G1_func_00b11660.m();
}
