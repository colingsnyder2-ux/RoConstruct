// roc 2012-06 006a62d0  unit: RBX::Lua::WeakThreadRef  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a62d0
//
// 006a62d0  8b442408             mov eax, dword ptr [esp + 8]
// 006a62d4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006a62d8  8b11                 mov edx, dword ptr [ecx]
// 006a62da  50                   push eax
// 006a62db  ffd2                 call edx
// 006a62dd  83c404               add esp, 4
// 006a62e0  c3                   ret 
// copied from an identical function in another client (function ?invoke@@YAHPAUS@@H@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S { int (__cdecl *f)(int); };

int invoke(S* s, int x)
{
    return s->f(x);
}