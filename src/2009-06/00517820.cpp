// from server: 100% by auto
// roc 2009-06 00517820  unit: RBX::VMaterialBase::?$WeakReferenceCountedPointer  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00517820
//
// 00517820  8b542404             mov edx, dword ptr [esp + 4]
// 00517824  8b4208               mov eax, dword ptr [edx + 8]
// 00517827  56                   push esi
// 00517828  8b30                 mov esi, dword ptr [eax]
// 0051782a  897208               mov dword ptr [edx + 8], esi
// 0051782d  8b30                 mov esi, dword ptr [eax]
// 0051782f  807e2100             cmp byte ptr [esi + 0x21], 0
// 00517833  7503                 jne 0x517838
// 00517835  895604               mov dword ptr [esi + 4], edx
// 00517838  8b7204               mov esi, dword ptr [edx + 4]
// 0051783b  897004               mov dword ptr [eax + 4], esi
// 0051783e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00517841  5e                   pop esi
// 00517842  3b5104               cmp edx, dword ptr [ecx + 4]
// 00517845  750b                 jne 0x517852
// 00517847  894104               mov dword ptr [ecx + 4], eax
// 0051784a  8910                 mov dword ptr [eax], edx
// 0051784c  894204               mov dword ptr [edx + 4], eax
// 0051784f  c20400               ret 4
// 00517852  8b4a04               mov ecx, dword ptr [edx + 4]
// 00517855  3b11                 cmp edx, dword ptr [ecx]
// 00517857  750a                 jne 0x517863
// 00517859  8901                 mov dword ptr [ecx], eax
// 0051785b  8910                 mov dword ptr [eax], edx
// 0051785d  894204               mov dword ptr [edx + 4], eax
// 00517860  c20400               ret 4
// 00517863  894108               mov dword ptr [ecx + 8], eax
// 00517866  8910                 mov dword ptr [eax], edx
// 00517868  894204               mov dword ptr [edx + 4], eax
// 0051786b  c20400               ret 4
// standard library set<pod20> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
