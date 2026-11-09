// roc 2012-06 00b1be70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1be70
//
// 00b1be70  b9189be400           mov ecx, 0xe49b18
// 00b1be75  e97660a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1be70 { void m(); };
extern T_func_00b1be70 G1_func_00b1be70;
void func_00b1be70()
{
    G1_func_00b1be70.m();
}
