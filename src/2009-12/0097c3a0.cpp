// from server: 100% by nuck16
// roc 2009-12 0097c3a0  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097c3a0
//
// 0097c3a0  ff158ccd9800         call dword ptr [0x98cd8c]
// 0097c3a6  a35c90b900           mov dword ptr [0xb9905c], eax
// 0097c3ab  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b9905c;

void f()
{
    g_b9905c = &imported_get();
}
