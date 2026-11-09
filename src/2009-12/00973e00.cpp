// from server: 100% by nuck16
// roc 2009-12 00973e00  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973e00
//
// 00973e00  ff1590cd9800         call dword ptr [0x98cd90]
// 00973e06  a3d416b900           mov dword ptr [0xb916d4], eax
// 00973e0b  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b916d4;

void f()
{
    g_b916d4 = &imported_get();
}
