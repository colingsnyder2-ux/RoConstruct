// from server: 100% by colin
// roc 2007-03 00438dd0  unit: seg_00430000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00438dd0
//
// 00438dd0  8b542404             mov edx, dword ptr [esp + 4]
// 00438dd4  8b01                 mov eax, dword ptr [ecx]
// 00438dd6  8b12                 mov edx, dword ptr [edx]
// 00438dd8  8b80e8000000         mov eax, dword ptr [eax + 0xe8]
// 00438dde  89542404             mov dword ptr [esp + 4], edx
// 00438de2  ffe0                 jmp eax
// copied from an identical function in another client (function ?f@S@@QAEXPBH@Z)

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
struct S;
typedef void (__thiscall *Method)(S *, int);

struct Table {
    Method unused[58];
    Method target;
};

struct S {
    Table *table;
    void f(const int *value);
};

void S::f(const int *value)
{
    return table->target(this, *value);
}