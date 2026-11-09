// roc 2012-06 00b12a20  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12a20
//
// 00b12a20  b918c3e100           mov ecx, 0xe1c318
// 00b12a25  ff252c30b200         jmp dword ptr [0xb2302c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b12a20 { void m(); };
extern T_func_00b12a20 G1_func_00b12a20;
void func_00b12a20()
{
    G1_func_00b12a20.m();
}
