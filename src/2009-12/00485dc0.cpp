// from server: 100% by auto
// roc 2009-12 00485dc0  unit: Ogre::GfxClustererPart  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00485dc0
//
// 00485dc0  55                   push ebp
// 00485dc1  8bec                 mov ebp, esp
// 00485dc3  6aff                 push -1
// 00485dc5  6891f39200           push 0x92f391
// 00485dca  64a100000000         mov eax, dword ptr fs:[0]
// 00485dd0  50                   push eax
// 00485dd1  64892500000000       mov dword ptr fs:[0], esp
// 00485dd8  83ec0c               sub esp, 0xc
// 00485ddb  53                   push ebx
// 00485ddc  56                   push esi
// 00485ddd  57                   push edi
// 00485dde  8965f0               mov dword ptr [ebp - 0x10], esp
// 00485de1  6a48                 push 0x48
// 00485de3  e878da3600           call 0x7f3860
// 00485de8  8bf0                 mov esi, eax
// 00485dea  83c404               add esp, 4
// 00485ded  8975ec               mov dword ptr [ebp - 0x14], esi
// 00485df0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00485df7  8975e8               mov dword ptr [ebp - 0x18], esi
// 00485dfa  c645fc01             mov byte ptr [ebp - 4], 1
// 00485dfe  85f6                 test esi, esi
// 00485e00  7427                 je 0x485e29
// 00485e02  8b4508               mov eax, dword ptr [ebp + 8]
// 00485e05  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00485e08  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00485e0b  8906                 mov dword ptr [esi], eax
// 00485e0d  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00485e10  894e04               mov dword ptr [esi + 4], ecx
// 00485e13  50                   push eax
// 00485e14  8d4e0c               lea ecx, [esi + 0xc]
// 00485e17  895608               mov dword ptr [esi + 8], edx
// 00485e1a  e801f2ffff           call 0x485020
// 00485e1f  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 00485e22  884e44               mov byte ptr [esi + 0x44], cl
// 00485e25  c6464500             mov byte ptr [esi + 0x45], 0
// 00485e29  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00485e2c  5f                   pop edi
// 00485e2d  8bc6                 mov eax, esi
// 00485e2f  5e                   pop esi
// 00485e30  64890d00000000       mov dword ptr fs:[0], ecx
// 00485e37  5b                   pop ebx
// 00485e38  8be5                 mov esp, ebp
// 00485e3a  5d                   pop ebp
// 00485e3b  c21400               ret 0x14
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@D@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
