// from server: 100% by auto
// roc 2007-08 00587a60  unit: RBX::Reflection::EnumDescriptor  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00587a60
//
// 00587a60  8b542404             mov edx, dword ptr [esp + 4]
// 00587a64  8b02                 mov eax, dword ptr [edx]
// 00587a66  56                   push esi
// 00587a67  8b7008               mov esi, dword ptr [eax + 8]
// 00587a6a  8932                 mov dword ptr [edx], esi
// 00587a6c  8b7008               mov esi, dword ptr [eax + 8]
// 00587a6f  807e3500             cmp byte ptr [esi + 0x35], 0
// 00587a73  7503                 jne 0x587a78
// 00587a75  895604               mov dword ptr [esi + 4], edx
// 00587a78  8b7204               mov esi, dword ptr [edx + 4]
// 00587a7b  897004               mov dword ptr [eax + 4], esi
// 00587a7e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00587a81  3b5104               cmp edx, dword ptr [ecx + 4]
// 00587a84  5e                   pop esi
// 00587a85  750c                 jne 0x587a93
// 00587a87  894104               mov dword ptr [ecx + 4], eax
// 00587a8a  895008               mov dword ptr [eax + 8], edx
// 00587a8d  894204               mov dword ptr [edx + 4], eax
// 00587a90  c20400               ret 4
// 00587a93  8b4a04               mov ecx, dword ptr [edx + 4]
// 00587a96  3b5108               cmp edx, dword ptr [ecx + 8]
// 00587a99  750c                 jne 0x587aa7
// 00587a9b  894108               mov dword ptr [ecx + 8], eax
// 00587a9e  895008               mov dword ptr [eax + 8], edx
// 00587aa1  894204               mov dword ptr [edx + 4], eax
// 00587aa4  c20400               ret 4
// 00587aa7  8901                 mov dword ptr [ecx], eax
// 00587aa9  895008               mov dword ptr [eax + 8], edx
// 00587aac  894204               mov dword ptr [edx + 4], eax
// 00587aaf  c20400               ret 4
// standard library set<pod40> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
