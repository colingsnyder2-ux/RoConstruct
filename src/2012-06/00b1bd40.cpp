// roc 2012-06 00b1bd40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bd40
//
// 00b1bd40  b9409ee400           mov ecx, 0xe49e40
// 00b1bd45  e9a6acc7ff           jmp 0x7969f0
// auto-matched from its assembly shape

struct T_func_00b1bd40 { void m(); };
extern T_func_00b1bd40 G1_func_00b1bd40;
void func_00b1bd40()
{
    G1_func_00b1bd40.m();
}
