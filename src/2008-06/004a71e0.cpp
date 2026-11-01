// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 004a71e0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a71e0
//
// 004a71e0  55                   push ebp
// 004a71e1  8bec                 mov ebp, esp
// 004a71e3  6aff                 push -1
// 004a71e5  68417f7c00           push 0x7c7f41
// 004a71ea  64a100000000         mov eax, dword ptr fs:[0]
// 004a71f0  50                   push eax
// 004a71f1  64892500000000       mov dword ptr fs:[0], esp
// 004a71f8  83ec0c               sub esp, 0xc
// 004a71fb  53                   push ebx
// 004a71fc  56                   push esi
// 004a71fd  57                   push edi
// 004a71fe  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a7201  6a30                 push 0x30
// 004a7203  e818971f00           call 0x6a0920
// 004a7208  8bf0                 mov esi, eax
// 004a720a  83c404               add esp, 4
// 004a720d  8975ec               mov dword ptr [ebp - 0x14], esi
// 004a7210  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a7217  8975e8               mov dword ptr [ebp - 0x18], esi
// 004a721a  c645fc01             mov byte ptr [ebp - 4], 1
// 004a721e  85f6                 test esi, esi
// 004a7220  7430                 je 0x4a7252
// 004a7222  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004a7225  8b4508               mov eax, dword ptr [ebp + 8]
// 004a7228  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004a722b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 004a722e  894e04               mov dword ptr [esi + 4], ecx
// 004a7231  8d7e0c               lea edi, [esi + 0xc]
// 004a7234  53                   push ebx
// 004a7235  8bcf                 mov ecx, edi
// 004a7237  8906                 mov dword ptr [esi], eax
// 004a7239  895608               mov dword ptr [esi + 8], edx
// 004a723c  ff155c248000         call dword ptr [0x80245c]
// 004a7242  8a431c               mov al, byte ptr [ebx + 0x1c]
// 004a7245  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 004a7248  88471c               mov byte ptr [edi + 0x1c], al
// 004a724b  884e2c               mov byte ptr [esi + 0x2c], cl
// 004a724e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 004a7252  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a7255  5f                   pop edi
// 004a7256  8bc6                 mov eax, esi
// 004a7258  5e                   pop esi
// 004a7259  64890d00000000       mov dword ptr fs:[0], ecx
// 004a7260  5b                   pop ebx
// 004a7261  8be5                 mov esp, ebp
// 004a7263  5d                   pop ebp
// 004a7264  c21400               ret 0x14
// standard library map_str<char> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@2@D@Z)

// stl: map_str<char>
typedef char E;
#include <map>
#include <string>
template class std::map<std::string, E>;
