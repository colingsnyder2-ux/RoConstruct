// roc 2012-06 00b17620  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17620
//
// 00b17620  b9781fe300           mov ecx, 0xe31f78
// 00b17625  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b17620 { void m(); };
extern T_func_00b17620 G1_func_00b17620;
void func_00b17620()
{
    G1_func_00b17620.m();
}
