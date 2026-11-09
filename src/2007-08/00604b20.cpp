// from server: 100% by auto
// roc 2007-08 00604b20  unit: RBX::SleepStage  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00604b20
//
// 00604b20  8b542404             mov edx, dword ptr [esp + 4]
// 00604b24  8b02                 mov eax, dword ptr [edx]
// 00604b26  56                   push esi
// 00604b27  8b7008               mov esi, dword ptr [eax + 8]
// 00604b2a  8932                 mov dword ptr [edx], esi
// 00604b2c  8b7008               mov esi, dword ptr [eax + 8]
// 00604b2f  807e1500             cmp byte ptr [esi + 0x15], 0
// 00604b33  7503                 jne 0x604b38
// 00604b35  895604               mov dword ptr [esi + 4], edx
// 00604b38  8b7204               mov esi, dword ptr [edx + 4]
// 00604b3b  897004               mov dword ptr [eax + 4], esi
// 00604b3e  8b4904               mov ecx, dword ptr [ecx + 4]
// 00604b41  3b5104               cmp edx, dword ptr [ecx + 4]
// 00604b44  5e                   pop esi
// 00604b45  750c                 jne 0x604b53
// 00604b47  894104               mov dword ptr [ecx + 4], eax
// 00604b4a  895008               mov dword ptr [eax + 8], edx
// 00604b4d  894204               mov dword ptr [edx + 4], eax
// 00604b50  c20400               ret 4
// 00604b53  8b4a04               mov ecx, dword ptr [edx + 4]
// 00604b56  3b5108               cmp edx, dword ptr [ecx + 8]
// 00604b59  750c                 jne 0x604b67
// 00604b5b  894108               mov dword ptr [ecx + 8], eax
// 00604b5e  895008               mov dword ptr [eax + 8], edx
// 00604b61  894204               mov dword ptr [edx + 4], eax
// 00604b64  c20400               ret 4
// 00604b67  8901                 mov dword ptr [ecx], eax
// 00604b69  895008               mov dword ptr [eax + 8], edx
// 00604b6c  894204               mov dword ptr [edx + 4], eax
// 00604b6f  c20400               ret 4
// standard library set<pod8> (function ?_Rrotate@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
