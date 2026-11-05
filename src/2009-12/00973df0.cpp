// from server: 100% by nuck16
// roc 2009-12 00973df0  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973df0
//
// 00973df0  ff158ccd9800         call dword ptr [0x98cd8c]
// 00973df6  a3d016b900           mov dword ptr [0xb916d0], eax
// 00973dfb  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b916d0;

void f()
{
    g_b916d0 = &imported_get();
}
