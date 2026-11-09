// roc 2012-06 00b1ad40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ad40
//
// 00b1ad40  b9c857e400           mov ecx, 0xe457c8
// 00b1ad45  e9264c8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ad40 { void m(); };
extern T_func_00b1ad40 G1_func_00b1ad40;
void func_00b1ad40()
{
    G1_func_00b1ad40.m();
}
