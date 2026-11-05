// roc 2012-06 00b1ad10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ad10
//
// 00b1ad10  b9805de400           mov ecx, 0xe45d80
// 00b1ad15  e9564c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ad10 { void m(); };
extern T_func_00b1ad10 G1_func_00b1ad10;
void func_00b1ad10()
{
    G1_func_00b1ad10.m();
}
