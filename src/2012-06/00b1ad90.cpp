// roc 2012-06 00b1ad90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ad90
//
// 00b1ad90  b9404ee400           mov ecx, 0xe44e40
// 00b1ad95  e9d64b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ad90 { void m(); };
extern T_func_00b1ad90 G1_func_00b1ad90;
void func_00b1ad90()
{
    G1_func_00b1ad90.m();
}
