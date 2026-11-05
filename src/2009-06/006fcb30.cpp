// from server: 100% by auto
// roc 2009-06 006fcb30  unit: Ogre::VRbxFont::?$SharedPtr  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fcb30
//
// 006fcb30  8b542404             mov edx, dword ptr [esp + 4]
// 006fcb34  8b02                 mov eax, dword ptr [edx]
// 006fcb36  56                   push esi
// 006fcb37  8b7008               mov esi, dword ptr [eax + 8]
// 006fcb3a  8932                 mov dword ptr [edx], esi
// 006fcb3c  8b7008               mov esi, dword ptr [eax + 8]
// 006fcb3f  807e3500             cmp byte ptr [esi + 0x35], 0
// 006fcb43  7503                 jne 0x6fcb48
// 006fcb45  895604               mov dword ptr [esi + 4], edx
// 006fcb48  8b7204               mov esi, dword ptr [edx + 4]
// 006fcb4b  897004               mov dword ptr [eax + 4], esi
// 006fcb4e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006fcb51  5e                   pop esi
// 006fcb52  3b5104               cmp edx, dword ptr [ecx + 4]
// 006fcb55  750c                 jne 0x6fcb63
// 006fcb57  894104               mov dword ptr [ecx + 4], eax
// 006fcb5a  895008               mov dword ptr [eax + 8], edx
// 006fcb5d  894204               mov dword ptr [edx + 4], eax
// 006fcb60  c20400               ret 4
// 006fcb63  8b4a04               mov ecx, dword ptr [edx + 4]
// 006fcb66  3b5108               cmp edx, dword ptr [ecx + 8]
// 006fcb69  750c                 jne 0x6fcb77
// 006fcb6b  894108               mov dword ptr [ecx + 8], eax
// 006fcb6e  895008               mov dword ptr [eax + 8], edx
// 006fcb71  894204               mov dword ptr [edx + 4], eax
// 006fcb74  c20400               ret 4
// 006fcb77  8901                 mov dword ptr [ecx], eax
// 006fcb79  895008               mov dword ptr [eax + 8], edx
// 006fcb7c  894204               mov dword ptr [edx + 4], eax
// 006fcb7f  c20400               ret 4
// standard library set<pod40> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
