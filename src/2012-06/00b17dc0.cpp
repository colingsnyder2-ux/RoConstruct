// roc 2012-06 00b17dc0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17dc0
//
// 00b17dc0  b9403ce300           mov ecx, 0xe33c40
// 00b17dc5  e9a67b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b17dc0 { void m(); };
extern T_func_00b17dc0 G1_func_00b17dc0;
void func_00b17dc0()
{
    G1_func_00b17dc0.m();
}
