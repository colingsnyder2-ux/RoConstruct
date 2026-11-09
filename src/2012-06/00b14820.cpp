// roc 2012-06 00b14820  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14820
//
// 00b14820  b9884ee200           mov ecx, 0xe24e88
// 00b14825  e9e695a6ff           jmp 0x57de10
// auto-matched from its assembly shape

struct T_func_00b14820 { void m(); };
extern T_func_00b14820 G1_func_00b14820;
void func_00b14820()
{
    G1_func_00b14820.m();
}
