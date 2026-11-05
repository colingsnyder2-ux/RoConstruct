// from server: 100% by auto
// roc 2009-06 005da990  unit: std::D::DU?$char_traits::V?$basic_string::?$sp_counted_impl_p  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005da990
//
// 005da990  55                   push ebp
// 005da991  8bec                 mov ebp, esp
// 005da993  6aff                 push -1
// 005da995  6801348600           push 0x863401
// 005da99a  64a100000000         mov eax, dword ptr fs:[0]
// 005da9a0  50                   push eax
// 005da9a1  64892500000000       mov dword ptr fs:[0], esp
// 005da9a8  83ec0c               sub esp, 0xc
// 005da9ab  53                   push ebx
// 005da9ac  56                   push esi
// 005da9ad  57                   push edi
// 005da9ae  8965f0               mov dword ptr [ebp - 0x10], esp
// 005da9b1  6a34                 push 0x34
// 005da9b3  e880e01300           call 0x718a38
// 005da9b8  8bf0                 mov esi, eax
// 005da9ba  83c404               add esp, 4
// 005da9bd  8975ec               mov dword ptr [ebp - 0x14], esi
// 005da9c0  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005da9c7  8975e8               mov dword ptr [ebp - 0x18], esi
// 005da9ca  c645fc01             mov byte ptr [ebp - 4], 1
// 005da9ce  85f6                 test esi, esi
// 005da9d0  741b                 je 0x5da9ed
// 005da9d2  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005da9d5  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005da9d8  8b5510               mov edx, dword ptr [ebp + 0x10]
// 005da9db  50                   push eax
// 005da9dc  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005da9df  51                   push ecx
// 005da9e0  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005da9e3  52                   push edx
// 005da9e4  50                   push eax
// 005da9e5  51                   push ecx
// 005da9e6  8bce                 mov ecx, esi
// 005da9e8  e893f9ffff           call 0x5da380
// 005da9ed  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005da9f0  5f                   pop edi
// 005da9f1  8bc6                 mov eax, esi
// 005da9f3  5e                   pop esi
// 005da9f4  64890d00000000       mov dword ptr fs:[0], ecx
// 005da9fb  5b                   pop ebx
// 005da9fc  8be5                 mov esp, ebp
// 005da9fe  5d                   pop ebp
// 005da9ff  c21400               ret 0x14
// standard library map_str<podc6> (function ?_Buynode@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@2@PAU342@00ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@D@Z)

// stl: map_str<podc6>
struct E { char v[6]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
