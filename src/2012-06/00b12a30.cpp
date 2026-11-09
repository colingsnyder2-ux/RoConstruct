// roc 2012-06 00b12a30  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12a30
//
// 00b12a30  b9c8c2e100           mov ecx, 0xe1c2c8
// 00b12a35  ff255c2eb200         jmp dword ptr [0xb22e5c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b12a30 { void m(); };
extern T_func_00b12a30 G1_func_00b12a30;
void func_00b12a30()
{
    G1_func_00b12a30.m();
}
