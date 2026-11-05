// from server: 100% by auto
// roc 2009-12 00513810  unit: RBX::Network::Players  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00513810
//
// 00513810  8b542404             mov edx, dword ptr [esp + 4]
// 00513814  8b4208               mov eax, dword ptr [edx + 8]
// 00513817  56                   push esi
// 00513818  8b30                 mov esi, dword ptr [eax]
// 0051381a  897208               mov dword ptr [edx + 8], esi
// 0051381d  8b30                 mov esi, dword ptr [eax]
// 0051381f  807e3100             cmp byte ptr [esi + 0x31], 0
// 00513823  7503                 jne 0x513828
// 00513825  895604               mov dword ptr [esi + 4], edx
// 00513828  8b7204               mov esi, dword ptr [edx + 4]
// 0051382b  897004               mov dword ptr [eax + 4], esi
// 0051382e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00513831  5e                   pop esi
// 00513832  3b5104               cmp edx, dword ptr [ecx + 4]
// 00513835  750b                 jne 0x513842
// 00513837  894104               mov dword ptr [ecx + 4], eax
// 0051383a  8910                 mov dword ptr [eax], edx
// 0051383c  894204               mov dword ptr [edx + 4], eax
// 0051383f  c20400               ret 4
// 00513842  8b4a04               mov ecx, dword ptr [edx + 4]
// 00513845  3b11                 cmp edx, dword ptr [ecx]
// 00513847  750a                 jne 0x513853
// 00513849  8901                 mov dword ptr [ecx], eax
// 0051384b  8910                 mov dword ptr [eax], edx
// 0051384d  894204               mov dword ptr [edx + 4], eax
// 00513850  c20400               ret 4
// 00513853  894108               mov dword ptr [ecx + 8], eax
// 00513856  8910                 mov dword ptr [eax], edx
// 00513858  894204               mov dword ptr [edx + 4], eax
// 0051385b  c20400               ret 4
// standard library set<pod36> (function ?_Lrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod36>
struct E { int v[9]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
