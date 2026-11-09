// roc 2012-06 00b11690  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11690
//
// 00b11690  b91875e100           mov ecx, 0xe17518
// 00b11695  e9d6e28fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b11690 { void m(); };
extern T_func_00b11690 G1_func_00b11690;
void func_00b11690()
{
    G1_func_00b11690.m();
}
