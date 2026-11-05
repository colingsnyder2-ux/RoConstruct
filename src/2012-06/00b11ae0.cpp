// roc 2012-06 00b11ae0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11ae0
//
// 00b11ae0  b95489e100           mov ecx, 0xe18954
// 00b11ae5  e906e492ff           jmp 0x43fef0
// auto-matched from its assembly shape

struct T_func_00b11ae0 { void m(); };
extern T_func_00b11ae0 G1_func_00b11ae0;
void func_00b11ae0()
{
    G1_func_00b11ae0.m();
}
