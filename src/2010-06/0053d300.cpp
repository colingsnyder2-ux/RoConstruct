// from server: 100% by auto
// roc 2010-06 0053d300  unit: RBX::ImmediateMeshGenAdapter  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053d300
//
// 0053d300  83ec08               sub esp, 8
// 0053d303  8b542414             mov edx, dword ptr [esp + 0x14]
// 0053d307  53                   push ebx
// 0053d308  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0053d30c  56                   push esi
// 0053d30d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0053d311  57                   push edi
// 0053d312  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0053d316  32c0                 xor al, al
// 0053d318  88442410             mov byte ptr [esp + 0x10], al
// 0053d31c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0053d320  8844240c             mov byte ptr [esp + 0xc], al
// 0053d324  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0053d328  50                   push eax
// 0053d329  51                   push ecx
// 0053d32a  52                   push edx
// 0053d32b  57                   push edi
// 0053d32c  56                   push esi
// 0053d32d  53                   push ebx
// 0053d32e  e86dfdffff           call 0x53d0a0
// 0053d333  2bf3                 sub esi, ebx
// 0053d335  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053d33a  f7ee                 imul esi
// 0053d33c  c1fa02               sar edx, 2
// 0053d33f  8bc2                 mov eax, edx
// 0053d341  c1e81f               shr eax, 0x1f
// 0053d344  03c2                 add eax, edx
// 0053d346  8d0440               lea eax, [eax + eax*2]
// 0053d349  03c0                 add eax, eax
// 0053d34b  03c0                 add eax, eax
// 0053d34d  03c0                 add eax, eax
// 0053d34f  83c418               add esp, 0x18
// 0053d352  8bc8                 mov ecx, eax
// 0053d354  8bc7                 mov eax, edi
// 0053d356  5f                   pop edi
// 0053d357  5e                   pop esi
// 0053d358  2bc1                 sub eax, ecx
// 0053d35a  5b                   pop ebx
// 0053d35b  83c408               add esp, 8
// 0053d35e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
