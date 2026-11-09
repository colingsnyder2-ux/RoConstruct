// from server: 100% by nuck16
// roc 2009-12 0097c370  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c370
//
// 0097c370  ff1590cd9800         call dword ptr [0x98cd90]
// 0097c376  a36c90b900           mov dword ptr [0xb9906c], eax
// 0097c37b  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b9906c;

void f()
{
    g_b9906c = &imported_get();
}
