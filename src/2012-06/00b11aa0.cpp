// roc 2012-06 00b11aa0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11aa0
//
// 00b11aa0  b94489e100           mov ecx, 0xe18944
// 00b11aa5  e986f792ff           jmp 0x441230
// auto-matched from its assembly shape

struct T_func_00b11aa0 { void m(); };
extern T_func_00b11aa0 G1_func_00b11aa0;
void func_00b11aa0()
{
    G1_func_00b11aa0.m();
}
