// from server: 100% by nuck16
// roc 2009-12 0097c390  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c390
//
// 0097c390  ff158ccd9800         call dword ptr [0x98cd8c]
// 0097c396  a37c90b900           mov dword ptr [0xb9907c], eax
// 0097c39b  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b9907c;

void f()
{
    g_b9907c = &imported_get();
}
