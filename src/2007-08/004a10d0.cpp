// from server: 100% by auto
// roc 2007-08 004a10d0  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 146 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a10d0
//
// 004a10d0  55                   push ebp
// 004a10d1  8bec                 mov ebp, esp
// 004a10d3  6aff                 push -1
// 004a10d5  6891957400           push 0x749591
// 004a10da  64a100000000         mov eax, dword ptr fs:[0]
// 004a10e0  50                   push eax
// 004a10e1  83ec0c               sub esp, 0xc
// 004a10e4  53                   push ebx
// 004a10e5  56                   push esi
// 004a10e6  57                   push edi
// 004a10e7  a188518b00           mov eax, dword ptr [0x8b5188]
// 004a10ec  33c5                 xor eax, ebp
// 004a10ee  50                   push eax
// 004a10ef  8d45f4               lea eax, [ebp - 0xc]
// 004a10f2  64a300000000         mov dword ptr fs:[0], eax
// 004a10f8  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a10fb  6a30                 push 0x30
// 004a10fd  e8f4ed1800           call 0x62fef6
// 004a1102  8bf0                 mov esi, eax
// 004a1104  83c404               add esp, 4
// 004a1107  8975ec               mov dword ptr [ebp - 0x14], esi
// 004a110a  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a1111  8975e8               mov dword ptr [ebp - 0x18], esi
// 004a1114  85f6                 test esi, esi
// 004a1116  c645fc01             mov byte ptr [ebp - 4], 1
// 004a111a  7430                 je 0x4a114c
// 004a111c  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004a111f  8b4508               mov eax, dword ptr [ebp + 8]
// 004a1122  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004a1125  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004a1128  894e04               mov dword ptr [esi + 4], ecx
// 004a112b  8d7e0c               lea edi, [esi + 0xc]
// 004a112e  53                   push ebx
// 004a112f  8bcf                 mov ecx, edi
// 004a1131  8906                 mov dword ptr [esi], eax
// 004a1133  895608               mov dword ptr [esi + 8], edx
// 004a1136  ff159ce67700         call dword ptr [0x77e69c]
// 004a113c  8a431c               mov al, byte ptr [ebx + 0x1c]
// 004a113f  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 004a1142  88471c               mov byte ptr [edi + 0x1c], al
// 004a1145  884e2c               mov byte ptr [esi + 0x2c], cl
// 004a1148  c6462d00             mov byte ptr [esi + 0x2d], 0
// 004a114c  8bc6                 mov eax, esi
// 004a114e  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a1151  64890d00000000       mov dword ptr fs:[0], ecx
// 004a1158  59                   pop ecx
// 004a1159  5f                   pop edi
// 004a115a  5e                   pop esi
// 004a115b  5b                   pop ebx
// 004a115c  8be5                 mov esp, ebp
// 004a115e  5d                   pop ebp
// 004a115f  c21400               ret 0x14
// standard library map_str<char> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@2@D@Z)

// stl: map_str<char>
typedef char E;
#include <map>
#include <string>
template class std::map<std::string, E>;
