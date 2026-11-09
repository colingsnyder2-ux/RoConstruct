// from server: 100% by auto
// roc 2009-06 004765a0  unit: Ogre::RbxMeshLoader  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004765a0
//
// 004765a0  55                   push ebp
// 004765a1  8bec                 mov ebp, esp
// 004765a3  6aff                 push -1
// 004765a5  68a1428500           push 0x8542a1
// 004765aa  64a100000000         mov eax, dword ptr fs:[0]
// 004765b0  50                   push eax
// 004765b1  64892500000000       mov dword ptr fs:[0], esp
// 004765b8  83ec0c               sub esp, 0xc
// 004765bb  53                   push ebx
// 004765bc  56                   push esi
// 004765bd  57                   push edi
// 004765be  8965f0               mov dword ptr [ebp - 0x10], esp
// 004765c1  6a48                 push 0x48
// 004765c3  e870242a00           call 0x718a38
// 004765c8  8bf0                 mov esi, eax
// 004765ca  83c404               add esp, 4
// 004765cd  8975ec               mov dword ptr [ebp - 0x14], esi
// 004765d0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004765d7  8975e8               mov dword ptr [ebp - 0x18], esi
// 004765da  c645fc01             mov byte ptr [ebp - 4], 1
// 004765de  85f6                 test esi, esi
// 004765e0  7427                 je 0x476609
// 004765e2  8b4508               mov eax, dword ptr [ebp + 8]
// 004765e5  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004765e8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004765eb  8906                 mov dword ptr [esi], eax
// 004765ed  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004765f0  894e04               mov dword ptr [esi + 4], ecx
// 004765f3  50                   push eax
// 004765f4  8d4e0c               lea ecx, [esi + 0xc]
// 004765f7  895608               mov dword ptr [esi + 8], edx
// 004765fa  e881f7ffff           call 0x475d80
// 004765ff  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 00476602  884e44               mov byte ptr [esi + 0x44], cl
// 00476605  c6464500             mov byte ptr [esi + 0x45], 0
// 00476609  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0047660c  5f                   pop edi
// 0047660d  8bc6                 mov eax, esi
// 0047660f  5e                   pop esi
// 00476610  64890d00000000       mov dword ptr fs:[0], ecx
// 00476617  5b                   pop ebx
// 00476618  8be5                 mov esp, ebp
// 0047661a  5d                   pop ebp
// 0047661b  c21400               ret 0x14
// standard library map_str<string> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@D@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
