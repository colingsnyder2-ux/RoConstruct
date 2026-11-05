// roc 2012-06 00b15600  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15600
//
// 00b15600  b9e092e200           mov ecx, 0xe292e0
// 00b15605  e966a38fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b15600 { void m(); };
extern T_func_00b15600 G1_func_00b15600;
void func_00b15600()
{
    G1_func_00b15600.m();
}
