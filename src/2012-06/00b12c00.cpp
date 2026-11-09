// roc 2012-06 00b12c00  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12c00
//
// 00b12c00  b994d4e100           mov ecx, 0xe1d494
// 00b12c05  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b12c00 { void m(); };
extern T_func_00b12c00 G1_func_00b12c00;
void func_00b12c00()
{
    G1_func_00b12c00.m();
}
