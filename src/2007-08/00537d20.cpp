// from server: 100% by colin
// roc 2007-08 00537d20  unit: RBX::Lua::ThreadRef::VNode::V?$shared_ptr::?$TItem  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00537d20
//
// 00537d20  8b442408             mov eax, dword ptr [esp + 8]
// 00537d24  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00537d28  8b11                 mov edx, dword ptr [ecx]
// 00537d2a  50                   push eax
// 00537d2b  ffd2                 call edx
// 00537d2d  83c404               add esp, 4
// 00537d30  c3                   ret 
// copied from an identical function in another client (function ?invoke@@YAHPAUS@@H@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S { int (__cdecl *f)(int); };

int invoke(S* s, int x)
{
    return s->f(x);
}