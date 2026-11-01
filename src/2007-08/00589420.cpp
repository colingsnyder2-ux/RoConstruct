// from server: 100% by colin
// roc 2007-08 00589420  unit: VStockSound::?$FactoryProduct  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00589420
//
// 00589420  8b442404             mov eax, dword ptr [esp + 4]
// 00589424  8b4804               mov ecx, dword ptr [eax + 4]
// 00589427  8b10                 mov edx, dword ptr [eax]
// 00589429  51                   push ecx
// 0058942a  ffd2                 call edx
// 0058942c  8b00                 mov eax, dword ptr [eax]
// 0058942e  83c404               add esp, 4
// 00589431  c3                   ret 
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