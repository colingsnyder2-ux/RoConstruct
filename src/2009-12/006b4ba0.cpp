// from server: 100% by auto
// roc 2009-12 006b4ba0  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b4ba0
//
// 006b4ba0  55                   push ebp
// 006b4ba1  8bec                 mov ebp, esp
// 006b4ba3  6aff                 push -1
// 006b4ba5  6801869400           push 0x948601
// 006b4baa  64a100000000         mov eax, dword ptr fs:[0]
// 006b4bb0  50                   push eax
// 006b4bb1  64892500000000       mov dword ptr fs:[0], esp
// 006b4bb8  83ec0c               sub esp, 0xc
// 006b4bbb  53                   push ebx
// 006b4bbc  56                   push esi
// 006b4bbd  57                   push edi
// 006b4bbe  8965f0               mov dword ptr [ebp - 0x10], esp
// 006b4bc1  6a38                 push 0x38
// 006b4bc3  e898ec1300           call 0x7f3860
// 006b4bc8  8bf0                 mov esi, eax
// 006b4bca  83c404               add esp, 4
// 006b4bcd  8975ec               mov dword ptr [ebp - 0x14], esi
// 006b4bd0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006b4bd7  8975e8               mov dword ptr [ebp - 0x18], esi
// 006b4bda  c645fc01             mov byte ptr [ebp - 4], 1
// 006b4bde  85f6                 test esi, esi
// 006b4be0  741b                 je 0x6b4bfd
// 006b4be2  8b4518               mov eax, dword ptr [ebp + 0x18]
// 006b4be5  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 006b4be8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 006b4beb  50                   push eax
// 006b4bec  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006b4bef  51                   push ecx
// 006b4bf0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 006b4bf3  52                   push edx
// 006b4bf4  50                   push eax
// 006b4bf5  51                   push ecx
// 006b4bf6  8bce                 mov ecx, esi
// 006b4bf8  e8a3f9ffff           call 0x6b45a0
// 006b4bfd  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 006b4c00  5f                   pop edi
// 006b4c01  8bc6                 mov eax, esi
// 006b4c03  5e                   pop esi
// 006b4c04  64890d00000000       mov dword ptr fs:[0], ecx
// 006b4c0b  5b                   pop ebx
// 006b4c0c  8be5                 mov esp, ebp
// 006b4c0e  5d                   pop ebp
// 006b4c0f  c21400               ret 0x14
// standard library map_str<pod12> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<pod12>
struct E { int v[3]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
