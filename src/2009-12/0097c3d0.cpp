// from server: 100% by nuck16
// roc 2009-12 0097c3d0  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c3d0
//
// 0097c3d0  ff1590cd9800         call dword ptr [0x98cd90]
// 0097c3d6  a36490b900           mov dword ptr [0xb99064], eax
// 0097c3db  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b99064;

void f()
{
    g_b99064 = &imported_get();
}
