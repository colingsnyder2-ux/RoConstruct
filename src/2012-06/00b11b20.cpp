// roc 2012-06 00b11b20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11b20
//
// 00b11b20  b96489e100           mov ecx, 0xe18964
// 00b11b25  e986d092ff           jmp 0x43ebb0
// auto-matched from its assembly shape

struct T_func_00b11b20 { void m(); };
extern T_func_00b11b20 G1_func_00b11b20;
void func_00b11b20()
{
    G1_func_00b11b20.m();
}
