// from server: 100% by auto
// roc 2010-06 00960fb0  unit: RBX::SphereBuilder  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00960fb0
//
// 00960fb0  55                   push ebp
// 00960fb1  8bec                 mov ebp, esp
// 00960fb3  6aff                 push -1
// 00960fb5  6831219c00           push 0x9c2131
// 00960fba  64a100000000         mov eax, dword ptr fs:[0]
// 00960fc0  50                   push eax
// 00960fc1  64892500000000       mov dword ptr fs:[0], esp
// 00960fc8  83ec0c               sub esp, 0xc
// 00960fcb  53                   push ebx
// 00960fcc  56                   push esi
// 00960fcd  57                   push edi
// 00960fce  8965f0               mov dword ptr [ebp - 0x10], esp
// 00960fd1  6a30                 push 0x30
// 00960fd3  e8c869e4ff           call 0x7a79a0
// 00960fd8  8bf0                 mov esi, eax
// 00960fda  83c404               add esp, 4
// 00960fdd  8975ec               mov dword ptr [ebp - 0x14], esi
// 00960fe0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00960fe7  8975e8               mov dword ptr [ebp - 0x18], esi
// 00960fea  c645fc01             mov byte ptr [ebp - 4], 1
// 00960fee  85f6                 test esi, esi
// 00960ff0  7430                 je 0x961022
// 00960ff2  8b4508               mov eax, dword ptr [ebp + 8]
// 00960ff5  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00960ff8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00960ffb  8906                 mov dword ptr [esi], eax
// 00960ffd  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00961000  894e04               mov dword ptr [esi + 4], ecx
// 00961003  895608               mov dword ptr [esi + 8], edx
// 00961006  8b08                 mov ecx, dword ptr [eax]
// 00961008  83c004               add eax, 4
// 0096100b  894e0c               mov dword ptr [esi + 0xc], ecx
// 0096100e  50                   push eax
// 0096100f  8d4e10               lea ecx, [esi + 0x10]
// 00961012  ff150ca49e00         call dword ptr [0x9ea40c]
// 00961018  8a5518               mov dl, byte ptr [ebp + 0x18]
// 0096101b  88562c               mov byte ptr [esi + 0x2c], dl
// 0096101e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 00961022  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00961025  5f                   pop edi
// 00961026  8bc6                 mov eax, esi
// 00961028  5e                   pop esi
// 00961029  64890d00000000       mov dword ptr fs:[0], ecx
// 00961030  5b                   pop ebx
// 00961031  8be5                 mov esp, ebp
// 00961033  5d                   pop ebp
// 00961034  c21400               ret 0x14
// standard library map_int<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@D@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
