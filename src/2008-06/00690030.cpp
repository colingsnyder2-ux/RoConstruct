// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 00690030  unit: Ogre::RbxSceneManagerFactory  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00690030
//
// 00690030  55                   push ebp
// 00690031  8bec                 mov ebp, esp
// 00690033  6aff                 push -1
// 00690035  68f1e27d00           push 0x7de2f1
// 0069003a  64a100000000         mov eax, dword ptr fs:[0]
// 00690040  50                   push eax
// 00690041  64892500000000       mov dword ptr fs:[0], esp
// 00690048  83ec0c               sub esp, 0xc
// 0069004b  53                   push ebx
// 0069004c  56                   push esi
// 0069004d  57                   push edi
// 0069004e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00690051  6a30                 push 0x30
// 00690053  e8c8080100           call 0x6a0920
// 00690058  8bf0                 mov esi, eax
// 0069005a  83c404               add esp, 4
// 0069005d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00690060  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00690067  8975e8               mov dword ptr [ebp - 0x18], esi
// 0069006a  c645fc01             mov byte ptr [ebp - 4], 1
// 0069006e  85f6                 test esi, esi
// 00690070  7430                 je 0x6900a2
// 00690072  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00690075  8b4508               mov eax, dword ptr [ebp + 8]
// 00690078  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0069007b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 0069007e  894e04               mov dword ptr [esi + 4], ecx
// 00690081  8d7e0c               lea edi, [esi + 0xc]
// 00690084  53                   push ebx
// 00690085  8bcf                 mov ecx, edi
// 00690087  8906                 mov dword ptr [esi], eax
// 00690089  895608               mov dword ptr [esi + 8], edx
// 0069008c  ff155c248000         call dword ptr [0x80245c]
// 00690092  8b431c               mov eax, dword ptr [ebx + 0x1c]
// 00690095  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 00690098  89471c               mov dword ptr [edi + 0x1c], eax
// 0069009b  884e2c               mov byte ptr [esi + 0x2c], cl
// 0069009e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 006900a2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006900a5  5f                   pop edi
// 006900a6  8bc6                 mov eax, esi
// 006900a8  5e                   pop esi
// 006900a9  64890d00000000       mov dword ptr fs:[0], ecx
// 006900b0  5b                   pop ebx
// 006900b1  8be5                 mov esp, ebp
// 006900b3  5d                   pop ebp
// 006900b4  c21400               ret 0x14
// standard library map_str<ptr> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@D@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
