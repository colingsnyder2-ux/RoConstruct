// from server: 100% by auto
// roc 2010-06 00730e20  unit: lua_exception  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00730e20
//
// 00730e20  83ec08               sub esp, 8
// 00730e23  8b542414             mov edx, dword ptr [esp + 0x14]
// 00730e27  53                   push ebx
// 00730e28  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00730e2c  56                   push esi
// 00730e2d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00730e31  57                   push edi
// 00730e32  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00730e36  32c0                 xor al, al
// 00730e38  88442410             mov byte ptr [esp + 0x10], al
// 00730e3c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00730e40  8844240c             mov byte ptr [esp + 0xc], al
// 00730e44  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00730e48  50                   push eax
// 00730e49  51                   push ecx
// 00730e4a  52                   push edx
// 00730e4b  57                   push edi
// 00730e4c  56                   push esi
// 00730e4d  53                   push ebx
// 00730e4e  e8edfbffff           call 0x730a40
// 00730e53  2bf3                 sub esi, ebx
// 00730e55  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00730e5a  f7ee                 imul esi
// 00730e5c  c1fa02               sar edx, 2
// 00730e5f  8bc2                 mov eax, edx
// 00730e61  c1e81f               shr eax, 0x1f
// 00730e64  03c2                 add eax, edx
// 00730e66  8d0440               lea eax, [eax + eax*2]
// 00730e69  03c0                 add eax, eax
// 00730e6b  03c0                 add eax, eax
// 00730e6d  03c0                 add eax, eax
// 00730e6f  83c418               add esp, 0x18
// 00730e72  8bc8                 mov ecx, eax
// 00730e74  8bc7                 mov eax, edi
// 00730e76  5f                   pop edi
// 00730e77  5e                   pop esi
// 00730e78  2bc1                 sub eax, ecx
// 00730e7a  5b                   pop ebx
// 00730e7b  83c408               add esp, 8
// 00730e7e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
