// from server: 100% by auto
// roc 2009-06 005d8fb0  unit: VAuthoringSettings::?$BoundPropGetSet  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d8fb0
//
// 005d8fb0  8b542404             mov edx, dword ptr [esp + 4]
// 005d8fb4  8b02                 mov eax, dword ptr [edx]
// 005d8fb6  56                   push esi
// 005d8fb7  8b7008               mov esi, dword ptr [eax + 8]
// 005d8fba  8932                 mov dword ptr [edx], esi
// 005d8fbc  8b7008               mov esi, dword ptr [eax + 8]
// 005d8fbf  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 005d8fc3  7503                 jne 0x5d8fc8
// 005d8fc5  895604               mov dword ptr [esi + 4], edx
// 005d8fc8  8b7204               mov esi, dword ptr [edx + 4]
// 005d8fcb  897004               mov dword ptr [eax + 4], esi
// 005d8fce  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 005d8fd1  5e                   pop esi
// 005d8fd2  3b5104               cmp edx, dword ptr [ecx + 4]
// 005d8fd5  750c                 jne 0x5d8fe3
// 005d8fd7  894104               mov dword ptr [ecx + 4], eax
// 005d8fda  895008               mov dword ptr [eax + 8], edx
// 005d8fdd  894204               mov dword ptr [edx + 4], eax
// 005d8fe0  c20400               ret 4
// 005d8fe3  8b4a04               mov ecx, dword ptr [edx + 4]
// 005d8fe6  3b5108               cmp edx, dword ptr [ecx + 8]
// 005d8fe9  750c                 jne 0x5d8ff7
// 005d8feb  894108               mov dword ptr [ecx + 8], eax
// 005d8fee  895008               mov dword ptr [eax + 8], edx
// 005d8ff1  894204               mov dword ptr [edx + 4], eax
// 005d8ff4  c20400               ret 4
// 005d8ff7  8901                 mov dword ptr [ecx], eax
// 005d8ff9  895008               mov dword ptr [eax + 8], edx
// 005d8ffc  894204               mov dword ptr [edx + 4], eax
// 005d8fff  c20400               ret 4
// standard library set<pod48> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod48>
struct E { int v[12]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
