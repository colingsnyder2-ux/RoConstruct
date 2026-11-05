// from server: 100% by colin
// roc 2007-03 00457230  unit: seg_00450000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00457230
//
// 00457230  8b442408             mov eax, dword ptr [esp + 8]
// 00457234  8b4804               mov ecx, dword ptr [eax + 4]
// 00457237  8b10                 mov edx, dword ptr [eax]
// 00457239  56                   push esi
// 0045723a  57                   push edi
// 0045723b  51                   push ecx
// 0045723c  ffd2                 call edx
// 0045723e  8bf0                 mov esi, eax
// 00457240  8b442410             mov eax, dword ptr [esp + 0x10]
// 00457244  83c404               add esp, 4
// 00457247  b916000000           mov ecx, 0x16
// 0045724c  8bf8                 mov edi, eax
// 0045724e  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00457250  5f                   pop edi
// 00457251  5e                   pop esi
// 00457252  c3                   ret 
// copied from an identical function in another client (function ?f@@YA?AUResult@@PAUS@@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Result {
    int data[22];
};

struct S {
    Result* (__cdecl *function)(void*);
    void* argument;
};

Result __cdecl f(S* s)
{
    return *s->function(s->argument);
}