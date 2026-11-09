// from server: 100% by auto
// roc 2009-06 006fcae0  unit: Ogre::VRbxFont::?$SharedPtr  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006fcae0
//
// 006fcae0  8b542404             mov edx, dword ptr [esp + 4]
// 006fcae4  8b4208               mov eax, dword ptr [edx + 8]
// 006fcae7  56                   push esi
// 006fcae8  8b30                 mov esi, dword ptr [eax]
// 006fcaea  897208               mov dword ptr [edx + 8], esi
// 006fcaed  8b30                 mov esi, dword ptr [eax]
// 006fcaef  807e3500             cmp byte ptr [esi + 0x35], 0
// 006fcaf3  7503                 jne 0x6fcaf8
// 006fcaf5  895604               mov dword ptr [esi + 4], edx
// 006fcaf8  8b7204               mov esi, dword ptr [edx + 4]
// 006fcafb  897004               mov dword ptr [eax + 4], esi
// 006fcafe  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 006fcb01  5e                   pop esi
// 006fcb02  3b5104               cmp edx, dword ptr [ecx + 4]
// 006fcb05  750b                 jne 0x6fcb12
// 006fcb07  894104               mov dword ptr [ecx + 4], eax
// 006fcb0a  8910                 mov dword ptr [eax], edx
// 006fcb0c  894204               mov dword ptr [edx + 4], eax
// 006fcb0f  c20400               ret 4
// 006fcb12  8b4a04               mov ecx, dword ptr [edx + 4]
// 006fcb15  3b11                 cmp edx, dword ptr [ecx]
// 006fcb17  750a                 jne 0x6fcb23
// 006fcb19  8901                 mov dword ptr [ecx], eax
// 006fcb1b  8910                 mov dword ptr [eax], edx
// 006fcb1d  894204               mov dword ptr [edx + 4], eax
// 006fcb20  c20400               ret 4
// 006fcb23  894108               mov dword ptr [ecx + 8], eax
// 006fcb26  8910                 mov dword ptr [eax], edx
// 006fcb28  894204               mov dword ptr [edx + 4], eax
// 006fcb2b  c20400               ret 4
// standard library set<pod40> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
