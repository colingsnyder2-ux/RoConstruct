// roc 2012-06 00b1af60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1af60
//
// 00b1af60  b9f816e400           mov ecx, 0xe416f8
// 00b1af65  e9064a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1af60 { void m(); };
extern T_func_00b1af60 G1_func_00b1af60;
void func_00b1af60()
{
    G1_func_00b1af60.m();
}
