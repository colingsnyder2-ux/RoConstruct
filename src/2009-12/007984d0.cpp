// from server: 100% by auto
// roc 2009-12 007984d0  unit: lua_exception  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007984d0
//
// 007984d0  83ec08               sub esp, 8
// 007984d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007984d7  53                   push ebx
// 007984d8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007984dc  56                   push esi
// 007984dd  8b742418             mov esi, dword ptr [esp + 0x18]
// 007984e1  57                   push edi
// 007984e2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007984e6  32c0                 xor al, al
// 007984e8  88442410             mov byte ptr [esp + 0x10], al
// 007984ec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007984f0  8844240c             mov byte ptr [esp + 0xc], al
// 007984f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007984f8  50                   push eax
// 007984f9  51                   push ecx
// 007984fa  52                   push edx
// 007984fb  57                   push edi
// 007984fc  56                   push esi
// 007984fd  53                   push ebx
// 007984fe  e84dfcffff           call 0x798150
// 00798503  2bf3                 sub esi, ebx
// 00798505  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0079850a  f7ee                 imul esi
// 0079850c  c1fa02               sar edx, 2
// 0079850f  8bc2                 mov eax, edx
// 00798511  c1e81f               shr eax, 0x1f
// 00798514  03c2                 add eax, edx
// 00798516  8d0440               lea eax, [eax + eax*2]
// 00798519  03c0                 add eax, eax
// 0079851b  03c0                 add eax, eax
// 0079851d  03c0                 add eax, eax
// 0079851f  83c418               add esp, 0x18
// 00798522  8bc8                 mov ecx, eax
// 00798524  8bc7                 mov eax, edi
// 00798526  5f                   pop edi
// 00798527  5e                   pop esi
// 00798528  2bc1                 sub eax, ecx
// 0079852a  5b                   pop ebx
// 0079852b  83c408               add esp, 8
// 0079852e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
