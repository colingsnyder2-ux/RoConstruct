// roc 2012-06 00b11850  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11850
//
// 00b11850  b96081e100           mov ecx, 0xe18160
// 00b11855  ff257026b200         jmp dword ptr [0xb22670]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b11850 { void m(); };
extern T_func_00b11850 G1_func_00b11850;
void func_00b11850()
{
    G1_func_00b11850.m();
}
