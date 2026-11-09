// from server: 100% by auto
// roc 2009-12 005341f0  unit: RBX::Network::IdSerializer  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005341f0
//
// 005341f0  55                   push ebp
// 005341f1  8bec                 mov ebp, esp
// 005341f3  6aff                 push -1
// 005341f5  6801969300           push 0x939601
// 005341fa  64a100000000         mov eax, dword ptr fs:[0]
// 00534200  50                   push eax
// 00534201  64892500000000       mov dword ptr fs:[0], esp
// 00534208  83ec0c               sub esp, 0xc
// 0053420b  53                   push ebx
// 0053420c  56                   push esi
// 0053420d  57                   push edi
// 0053420e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00534211  6a30                 push 0x30
// 00534213  e848f62b00           call 0x7f3860
// 00534218  8bf0                 mov esi, eax
// 0053421a  83c404               add esp, 4
// 0053421d  8975ec               mov dword ptr [ebp - 0x14], esi
// 00534220  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00534227  8975e8               mov dword ptr [ebp - 0x18], esi
// 0053422a  c645fc01             mov byte ptr [ebp - 4], 1
// 0053422e  85f6                 test esi, esi
// 00534230  7430                 je 0x534262
// 00534232  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00534235  8b4508               mov eax, dword ptr [ebp + 8]
// 00534238  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0053423b  8b5d14               mov ebx, dword ptr [ebp + 0x14]
// 0053423e  894e04               mov dword ptr [esi + 4], ecx
// 00534241  8d7e0c               lea edi, [esi + 0xc]
// 00534244  53                   push ebx
// 00534245  8bcf                 mov ecx, edi
// 00534247  8906                 mov dword ptr [esi], eax
// 00534249  895608               mov dword ptr [esi + 8], edx
// 0053424c  ff15f0b69800         call dword ptr [0x98b6f0]
// 00534252  8a431c               mov al, byte ptr [ebx + 0x1c]
// 00534255  8a4d18               mov cl, byte ptr [ebp + 0x18]
// 00534258  88471c               mov byte ptr [edi + 0x1c], al
// 0053425b  884e2c               mov byte ptr [esi + 0x2c], cl
// 0053425e  c6462d00             mov byte ptr [esi + 0x2d], 0
// 00534262  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00534265  5f                   pop edi
// 00534266  8bc6                 mov eax, esi
// 00534268  5e                   pop esi
// 00534269  64890d00000000       mov dword ptr fs:[0], ecx
// 00534270  5b                   pop ebx
// 00534271  8be5                 mov esp, ebp
// 00534273  5d                   pop ebp
// 00534274  c21400               ret 0x14
// standard library map_str<char> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@DU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@D@2@D@Z)

// stl: map_str<char>
typedef char E;
#include <map>
#include <string>
template class std::map<std::string, E>;
