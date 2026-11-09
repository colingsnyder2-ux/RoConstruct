// from server: 100% by nuck16
// roc 2009-12 00973dc0  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973dc0
//
// 00973dc0  ff1590cd9800         call dword ptr [0x98cd90]
// 00973dc6  a3d816b900           mov dword ptr [0xb916d8], eax
// 00973dcb  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b916d8;

void f()
{
    g_b916d8 = &imported_get();
}
