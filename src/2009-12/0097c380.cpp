// from server: 100% by nuck16
// roc 2009-12 0097c380  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c380
//
// 0097c380  ff158ccd9800         call dword ptr [0x98cd8c]
// 0097c386  a37090b900           mov dword ptr [0xb99070], eax
// 0097c38b  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b99070;

void f()
{
    g_b99070 = &imported_get();
}
