// roc 2012-06 00b1ad20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ad20
//
// 00b1ad20  b9985be400           mov ecx, 0xe45b98
// 00b1ad25  e9464c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ad20 { void m(); };
extern T_func_00b1ad20 G1_func_00b1ad20;
void func_00b1ad20()
{
    G1_func_00b1ad20.m();
}
