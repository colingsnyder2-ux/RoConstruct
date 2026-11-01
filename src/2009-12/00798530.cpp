// from server: 100% by auto
// roc 2009-12 00798530  unit: lua_exception  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00798530
//
// 00798530  83ec08               sub esp, 8
// 00798533  8b542414             mov edx, dword ptr [esp + 0x14]
// 00798537  53                   push ebx
// 00798538  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0079853c  56                   push esi
// 0079853d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00798541  57                   push edi
// 00798542  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00798546  32c0                 xor al, al
// 00798548  88442410             mov byte ptr [esp + 0x10], al
// 0079854c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00798550  8844240c             mov byte ptr [esp + 0xc], al
// 00798554  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00798558  50                   push eax
// 00798559  51                   push ecx
// 0079855a  52                   push edx
// 0079855b  57                   push edi
// 0079855c  56                   push esi
// 0079855d  53                   push ebx
// 0079855e  e87dfcffff           call 0x7981e0
// 00798563  2bf3                 sub esi, ebx
// 00798565  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0079856a  f7ee                 imul esi
// 0079856c  c1fa02               sar edx, 2
// 0079856f  8bc2                 mov eax, edx
// 00798571  c1e81f               shr eax, 0x1f
// 00798574  03c2                 add eax, edx
// 00798576  8d0440               lea eax, [eax + eax*2]
// 00798579  03c0                 add eax, eax
// 0079857b  03c0                 add eax, eax
// 0079857d  03c0                 add eax, eax
// 0079857f  83c418               add esp, 0x18
// 00798582  8bc8                 mov ecx, eax
// 00798584  8bc7                 mov eax, edi
// 00798586  5f                   pop edi
// 00798587  5e                   pop esi
// 00798588  2bc1                 sub eax, ecx
// 0079858a  5b                   pop ebx
// 0079858b  83c408               add esp, 8
// 0079858e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
