// roc 2012-06 00b17590  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17590
//
// 00b17590  b9ec1ce300           mov ecx, 0xe31cec
// 00b17595  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b17590 { void m(); };
extern T_func_00b17590 G1_func_00b17590;
void func_00b17590()
{
    G1_func_00b17590.m();
}
