// roc 2012-06 00b117c0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b117c0
//
// 00b117c0  b95480e100           mov ecx, 0xe18054
// 00b117c5  e9768b90ff           jmp 0x41a340
// auto-matched from its assembly shape

struct T_func_00b117c0 { void m(); };
extern T_func_00b117c0 G1_func_00b117c0;
void func_00b117c0()
{
    G1_func_00b117c0.m();
}
