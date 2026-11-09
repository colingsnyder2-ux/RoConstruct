// roc 2012-06 00b12b40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12b40
//
// 00b12b40  b948cce100           mov ecx, 0xe1cc48
// 00b12b45  e926ce8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b12b40 { void m(); };
extern T_func_00b12b40 G1_func_00b12b40;
void func_00b12b40()
{
    G1_func_00b12b40.m();
}
