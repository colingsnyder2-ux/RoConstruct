// roc 2012-06 00b128e0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b128e0
//
// 00b128e0  b9a0a9e100           mov ecx, 0xe1a9a0
// 00b128e5  e986d08fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b128e0 { void m(); };
extern T_func_00b128e0 G1_func_00b128e0;
void func_00b128e0()
{
    G1_func_00b128e0.m();
}
