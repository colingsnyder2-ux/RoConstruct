// from server: 100% by auto
// roc 2010-06 00755710  unit: RBX::Block  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00755710
//
// 00755710  8b542404             mov edx, dword ptr [esp + 4]
// 00755714  8b02                 mov eax, dword ptr [edx]
// 00755716  56                   push esi
// 00755717  8b7008               mov esi, dword ptr [eax + 8]
// 0075571a  8932                 mov dword ptr [edx], esi
// 0075571c  8b7008               mov esi, dword ptr [eax + 8]
// 0075571f  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 00755723  7503                 jne 0x755728
// 00755725  895604               mov dword ptr [esi + 4], edx
// 00755728  8b7204               mov esi, dword ptr [edx + 4]
// 0075572b  897004               mov dword ptr [eax + 4], esi
// 0075572e  8b4918               mov ecx, dword ptr [ecx + 0x18]
// 00755731  5e                   pop esi
// 00755732  3b5104               cmp edx, dword ptr [ecx + 4]
// 00755735  750c                 jne 0x755743
// 00755737  894104               mov dword ptr [ecx + 4], eax
// 0075573a  895008               mov dword ptr [eax + 8], edx
// 0075573d  894204               mov dword ptr [edx + 4], eax
// 00755740  c20400               ret 4
// 00755743  8b4a04               mov ecx, dword ptr [edx + 4]
// 00755746  3b5108               cmp edx, dword ptr [ecx + 8]
// 00755749  750c                 jne 0x755757
// 0075574b  894108               mov dword ptr [ecx + 8], eax
// 0075574e  895008               mov dword ptr [eax + 8], edx
// 00755751  894204               mov dword ptr [edx + 4], eax
// 00755754  c20400               ret 4
// 00755757  8901                 mov dword ptr [ecx], eax
// 00755759  895008               mov dword ptr [eax + 8], edx
// 0075575c  894204               mov dword ptr [edx + 4], eax
// 0075575f  c20400               ret 4
// standard library set<pod16> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
