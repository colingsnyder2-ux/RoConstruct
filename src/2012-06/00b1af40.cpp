// roc 2012-06 00b1af40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1af40
//
// 00b1af40  b9c81ae400           mov ecx, 0xe41ac8
// 00b1af45  e9264a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1af40 { void m(); };
extern T_func_00b1af40 G1_func_00b1af40;
void func_00b1af40()
{
    G1_func_00b1af40.m();
}
