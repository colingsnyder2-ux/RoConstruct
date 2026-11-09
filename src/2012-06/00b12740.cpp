// roc 2012-06 00b12740  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12740
//
// 00b12740  b940a6e100           mov ecx, 0xe1a640
// 00b12745  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b12740 { void m(); };
extern T_func_00b12740 G1_func_00b12740;
void func_00b12740()
{
    G1_func_00b12740.m();
}
