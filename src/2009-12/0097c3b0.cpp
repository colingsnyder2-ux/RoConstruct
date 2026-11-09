// from server: 100% by nuck16
// roc 2009-12 0097c3b0  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c3b0
//
// 0097c3b0  ff1590cd9800         call dword ptr [0x98cd90]
// 0097c3b6  a36890b900           mov dword ptr [0xb99068], eax
// 0097c3bb  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b99068;

void f()
{
    g_b99068 = &imported_get();
}
