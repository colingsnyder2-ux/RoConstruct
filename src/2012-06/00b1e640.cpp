// roc 2012-06 00b1e640  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e640
//
// 00b1e640  b94808e500           mov ecx, 0xe50848
// 00b1e645  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b1e640 { void m(); };
extern T_func_00b1e640 G1_func_00b1e640;
void func_00b1e640()
{
    G1_func_00b1e640.m();
}
