// from server: 100% by colin
// roc 2007-03 0058bee0  unit: seg_00580000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0058bee0
//
// 0058bee0  8b442404             mov eax, dword ptr [esp + 4]
// 0058bee4  8b4804               mov ecx, dword ptr [eax + 4]
// 0058bee7  8b10                 mov edx, dword ptr [eax]
// 0058bee9  51                   push ecx
// 0058beea  ffd2                 call edx
// 0058beec  8b00                 mov eax, dword ptr [eax]
// 0058beee  83c404               add esp, 4
// 0058bef1  c3                   ret 
// copied from an identical function in another client (function ?f@@YAHPAUS@@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    int* (__cdecl *function)(void*);
    void* argument;
};

int __cdecl f(S* s)
{
    return *s->function(s->argument);
}