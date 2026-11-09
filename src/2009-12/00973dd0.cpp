// from server: 100% by nuck16
// roc 2009-12 00973dd0  unit: seg_00970000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00973dd0
//
// 00973dd0  ff158ccd9800         call dword ptr [0x98cd8c]
// 00973dd6  a3dc16b900           mov dword ptr [0xb916dc], eax
// 00973ddb  c3                   ret 

struct Value
{
};

extern "C" __declspec(dllimport) Value& __cdecl imported_get();

Value* g_b916dc;

void f()
{
    g_b916dc = &imported_get();
}
