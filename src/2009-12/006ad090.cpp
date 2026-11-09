// from server: 100% by auto
// roc 2009-12 006ad090  unit: RBX::Accoutrement  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ad090
//
// 006ad090  8b542404             mov edx, dword ptr [esp + 4]
// 006ad094  8b02                 mov eax, dword ptr [edx]
// 006ad096  56                   push esi
// 006ad097  8b7008               mov esi, dword ptr [eax + 8]
// 006ad09a  8932                 mov dword ptr [edx], esi
// 006ad09c  8b7008               mov esi, dword ptr [eax + 8]
// 006ad09f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 006ad0a3  7503                 jne 0x6ad0a8
// 006ad0a5  895604               mov dword ptr [esi + 4], edx
// 006ad0a8  8b7204               mov esi, dword ptr [edx + 4]
// 006ad0ab  897004               mov dword ptr [eax + 4], esi
// 006ad0ae  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006ad0b1  5e                   pop esi
// 006ad0b2  3b5104               cmp edx, dword ptr [ecx + 4]
// 006ad0b5  750c                 jne 0x6ad0c3
// 006ad0b7  894104               mov dword ptr [ecx + 4], eax
// 006ad0ba  895008               mov dword ptr [eax + 8], edx
// 006ad0bd  894204               mov dword ptr [edx + 4], eax
// 006ad0c0  c20400               ret 4
// 006ad0c3  8b4a04               mov ecx, dword ptr [edx + 4]
// 006ad0c6  3b5108               cmp edx, dword ptr [ecx + 8]
// 006ad0c9  750c                 jne 0x6ad0d7
// 006ad0cb  894108               mov dword ptr [ecx + 8], eax
// 006ad0ce  895008               mov dword ptr [eax + 8], edx
// 006ad0d1  894204               mov dword ptr [edx + 4], eax
// 006ad0d4  c20400               ret 4
// 006ad0d7  8901                 mov dword ptr [ecx], eax
// 006ad0d9  895008               mov dword ptr [eax + 8], edx
// 006ad0dc  894204               mov dword ptr [edx + 4], eax
// 006ad0df  c20400               ret 4
// standard library set<pod32> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
