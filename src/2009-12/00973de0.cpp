// from server: 100% by nuck16
// roc 2009-12 00973de0  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973de0
//
// 00973de0  ff158ccd9800         call dword ptr [0x98cd8c]
// 00973de6  a3e016b900           mov dword ptr [0xb916e0], eax
// 00973deb  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b916e0;

void f()
{
    g_b916e0 = &imported_get();
}
