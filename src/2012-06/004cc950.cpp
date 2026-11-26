// from server: 100% by Xemicl
// roc 2012-06 004cc950  unit: std::D::DU?$char_traits::V?$basic_string::V?$_Tset_traits::?$_Tree_nod::PAU_Node::?$STLAllocator  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cc950
//
// 004cc950  53                   push ebx
// 004cc951  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004cc955  56                   push esi
// 004cc956  8b742410             mov esi, dword ptr [esp + 0x10]
// 004cc95a  3bde                 cmp ebx, esi
// 004cc95c  7424                 je 0x4cc982
// 004cc95e  57                   push edi
// 004cc95f  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004cc963  83ee20               sub esi, 0x20
// 004cc966  83ef20               sub edi, 0x20
// 004cc969  56                   push esi
// 004cc96a  8bcf                 mov ecx, edi
// 004cc96c  ff155826b200         call dword ptr [0xb22658]
// 004cc972  8b461c               mov eax, dword ptr [esi + 0x1c]
// 004cc975  89471c               mov dword ptr [edi + 0x1c], eax
// 004cc978  3bf3                 cmp esi, ebx
// 004cc97a  75e7                 jne 0x4cc963
// 004cc97c  8bc7                 mov eax, edi
// 004cc97e  5f                   pop edi
// 004cc97f  5e                   pop esi
// 004cc980  5b                   pop ebx
// 004cc981  c3                   ret 
// 004cc982  8b442414             mov eax, dword ptr [esp + 0x14]
// 004cc986  5e                   pop esi
// 004cc987  5b                   pop ebx
// 004cc988  c3                   ret 
// copied from an identical function in another client (function ?copy_range@@YAPAUElem@@PAU1@00@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Elem { std::string s; int v; };
Elem* copy_range(Elem* first, Elem* last, Elem* dest)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}