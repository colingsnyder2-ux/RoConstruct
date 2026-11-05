// from server: 100% by auto
// roc 2010-06 0065b690  unit: RBX::ScriptInformationProvider  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0065b690
//
// 0065b690  55                   push ebp
// 0065b691  8bec                 mov ebp, esp
// 0065b693  6aff                 push -1
// 0065b695  6891e39900           push 0x99e391
// 0065b69a  64a100000000         mov eax, dword ptr fs:[0]
// 0065b6a0  50                   push eax
// 0065b6a1  64892500000000       mov dword ptr fs:[0], esp
// 0065b6a8  83ec0c               sub esp, 0xc
// 0065b6ab  53                   push ebx
// 0065b6ac  56                   push esi
// 0065b6ad  57                   push edi
// 0065b6ae  8965f0               mov dword ptr [ebp - 0x10], esp
// 0065b6b1  6a34                 push 0x34
// 0065b6b3  e8e8c21400           call 0x7a79a0
// 0065b6b8  8bf0                 mov esi, eax
// 0065b6ba  83c404               add esp, 4
// 0065b6bd  8975ec               mov dword ptr [ebp - 0x14], esi
// 0065b6c0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0065b6c7  8975e8               mov dword ptr [ebp - 0x18], esi
// 0065b6ca  c645fc01             mov byte ptr [ebp - 4], 1
// 0065b6ce  85f6                 test esi, esi
// 0065b6d0  7436                 je 0x65b708
// 0065b6d2  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0065b6d5  8b4508               mov eax, dword ptr [ebp + 8]
// 0065b6d8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0065b6db  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 0065b6de  894e04               mov dword ptr [esi + 4], ecx
// 0065b6e1  8d7e0c               lea edi, [esi + 0xc]
// 0065b6e4  53                   push ebx
// 0065b6e5  8bcf                 mov ecx, edi
// 0065b6e7  8906                 mov dword ptr [esi], eax
// 0065b6e9  895608               mov dword ptr [esi + 8], edx
// 0065b6ec  ff150ca49e00         call dword ptr [0x9ea40c]
// 0065b6f2  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 0065b6f5  8a5518               mov dl, byte ptr [ebp + 0x18]
// 0065b6f8  89471c               mov dword ptr [edi + 0x1c], eax
// 0065b6fb  8b4b20               mov ecx, dword ptr [ebx + 0x20]
// 0065b6fe  894f20               mov dword ptr [edi + 0x20], ecx
// 0065b701  885630               mov byte ptr [esi + 0x30], dl
// 0065b704  c6463100             mov byte ptr [esi + 0x31], 0
// 0065b708  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0065b70b  5f                   pop edi
// 0065b70c  8bc6                 mov eax, esi
// 0065b70e  5e                   pop esi
// 0065b70f  64890d00000000       mov dword ptr fs:[0], ecx
// 0065b716  5b                   pop ebx
// 0065b717  8be5                 mov esp, ebp
// 0065b719  5d                   pop ebp
// 0065b71a  c21400               ret 0x14
// standard library map_str<pod8> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
