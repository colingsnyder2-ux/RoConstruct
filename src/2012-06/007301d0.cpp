// from server: 100% by auto
// roc 2012-06 007301d0  unit: RBX::VGameBasicSettings::?$FactoryProduct  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007301d0
//
// 007301d0  55                   push ebp
// 007301d1  8bec                 mov ebp, esp
// 007301d3  6aff                 push -1
// 007301d5  686104ac00           push 0xac0461
// 007301da  64a100000000         mov eax, dword ptr fs:[0]
// 007301e0  50                   push eax
// 007301e1  64892500000000       mov dword ptr fs:[0], esp
// 007301e8  83ec0c               sub esp, 0xc
// 007301eb  53                   push ebx
// 007301ec  56                   push esi
// 007301ed  57                   push edi
// 007301ee  8965f0               mov dword ptr [ebp - 0x10], esp
// 007301f1  6a30                 push 0x30
// 007301f3  e8221f2500           call 0x98211a
// 007301f8  8bf0                 mov esi, eax
// 007301fa  83c404               add esp, 4
// 007301fd  8975ec               mov dword ptr [ebp - 0x14], esi
// 00730200  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00730207  8975e8               mov dword ptr [ebp - 0x18], esi
// 0073020a  c645fc01             mov byte ptr [ebp - 4], 1
// 0073020e  85f6                 test esi, esi
// 00730210  7430                 je 0x730242
// 00730212  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00730215  8b4508               mov eax, dword ptr [ebp + 8]
// 00730218  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0073021b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 0073021e  894e04               mov dword ptr [esi + 4], ecx
// 00730221  8d7e0c               lea edi, [esi + 0xc]
// 00730224  53                   push ebx
// 00730225  8bcf                 mov ecx, edi
// 00730227  8906                 mov dword ptr [esi], eax
// 00730229  895608               mov dword ptr [esi + 8], edx
// 0073022c  ff154426b200         call dword ptr [0xb22644]
// 00730232  8a431c               mov al, byte ptr [ebx + 0x1c]
// 00730235  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 00730238  88471c               mov byte ptr [edi + 0x1c], al
// 0073023b  884e2c               mov byte ptr [esi + 0x2c], cl
// 0073023e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 00730242  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00730245  5f                   pop edi
// 00730246  8bc6                 mov eax, esi
// 00730248  5e                   pop esi
// 00730249  64890d00000000       mov dword ptr fs:[0], ecx
// 00730250  5b                   pop ebx
// 00730251  8be5                 mov esp, ebp
// 00730253  5d                   pop ebp
// 00730254  c21400               ret 0x14
// standard library map_str<char> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@2@D@Z)

// stl: map_str<char>
typedef char E;
#include <map>
#include <string>
template class std::map<std::string, E>;
