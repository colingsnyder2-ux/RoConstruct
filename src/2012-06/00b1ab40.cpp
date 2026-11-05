// roc 2012-06 00b1ab40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ab40
//
// 00b1ab40  b99082e300           mov ecx, 0xe38290
// 00b1ab45  e986ffc4ff           jmp 0x76aad0
// auto-matched from its assembly shape

struct T_func_00b1ab40 { void m(); };
extern T_func_00b1ab40 G1_func_00b1ab40;
void func_00b1ab40()
{
    G1_func_00b1ab40.m();
}
