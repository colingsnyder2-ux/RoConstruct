// roc 2012-06 00b12b00  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12b00
//
// 00b12b00  b9bcc9e100           mov ecx, 0xe1c9bc
// 00b12b05  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b12b00 { void m(); };
extern T_func_00b12b00 G1_func_00b12b00;
void func_00b12b00()
{
    G1_func_00b12b00.m();
}
