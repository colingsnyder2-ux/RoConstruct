// from server: 100% by auto
// roc 2011-06 00773f20  unit: RBX::Lua::VWaitScriptSlot::?$TGenericSlotWrapper  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00773f20
//
// 00773f20  55                   push ebp
// 00773f21  8bec                 mov ebp, esp
// 00773f23  6aff                 push -1
// 00773f25  6881b09f00           push 0x9fb081
// 00773f2a  64a100000000         mov eax, dword ptr fs:[0]
// 00773f30  50                   push eax
// 00773f31  64892500000000       mov dword ptr fs:[0], esp
// 00773f38  83ec0c               sub esp, 0xc
// 00773f3b  53                   push ebx
// 00773f3c  56                   push esi
// 00773f3d  57                   push edi
// 00773f3e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00773f41  6a48                 push 0x48
// 00773f43  e816610900           call 0x80a05e
// 00773f48  8bf0                 mov esi, eax
// 00773f4a  83c404               add esp, 4
// 00773f4d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00773f50  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00773f57  8975e8               mov dword ptr [ebp - 0x18], esi
// 00773f5a  c645fc01             mov byte ptr [ebp - 4], 1
// 00773f5e  85f6                 test esi, esi
// 00773f60  7427                 je 0x773f89
// 00773f62  8b4508               mov eax, dword ptr [ebp + 8]
// 00773f65  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00773f68  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00773f6b  8906                 mov dword ptr [esi], eax
// 00773f6d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00773f70  894e04               mov dword ptr [esi + 4], ecx
// 00773f73  50                   push eax
// 00773f74  8d4e0c               lea ecx, [esi + 0xc]
// 00773f77  895608               mov dword ptr [esi + 8], edx
// 00773f7a  e811dbf4ff           call 0x6c1a90
// 00773f7f  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 00773f82  884e44               mov byte ptr [esi + 0x44], cl
// 00773f85  c6464500             mov byte ptr [esi + 0x45], 0
// 00773f89  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00773f8c  5f                   pop edi
// 00773f8d  8bc6                 mov eax, esi
// 00773f8f  5e                   pop esi
// 00773f90  64890d00000000       mov dword ptr fs:[0], ecx
// 00773f97  5b                   pop ebx
// 00773f98  8be5                 mov esp, ebp
// 00773f9a  5d                   pop ebp
// 00773f9b  c21400               ret 0x14
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@D@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
