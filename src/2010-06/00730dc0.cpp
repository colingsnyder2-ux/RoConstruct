// from server: 100% by auto
// roc 2010-06 00730dc0  unit: lua_exception  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00730dc0
//
// 00730dc0  83ec08               sub esp, 8
// 00730dc3  8b542414             mov edx, dword ptr [esp + 0x14]
// 00730dc7  53                   push ebx
// 00730dc8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00730dcc  56                   push esi
// 00730dcd  8b742418             mov esi, dword ptr [esp + 0x18]
// 00730dd1  57                   push edi
// 00730dd2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00730dd6  32c0                 xor al, al
// 00730dd8  88442410             mov byte ptr [esp + 0x10], al
// 00730ddc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00730de0  8844240c             mov byte ptr [esp + 0xc], al
// 00730de4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00730de8  50                   push eax
// 00730de9  51                   push ecx
// 00730dea  52                   push edx
// 00730deb  57                   push edi
// 00730dec  56                   push esi
// 00730ded  53                   push ebx
// 00730dee  e8bdfbffff           call 0x7309b0
// 00730df3  2bf3                 sub esi, ebx
// 00730df5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00730dfa  f7ee                 imul esi
// 00730dfc  c1fa02               sar edx, 2
// 00730dff  8bc2                 mov eax, edx
// 00730e01  c1e81f               shr eax, 0x1f
// 00730e04  03c2                 add eax, edx
// 00730e06  8d0440               lea eax, [eax + eax*2]
// 00730e09  03c0                 add eax, eax
// 00730e0b  03c0                 add eax, eax
// 00730e0d  03c0                 add eax, eax
// 00730e0f  83c418               add esp, 0x18
// 00730e12  8bc8                 mov ecx, eax
// 00730e14  8bc7                 mov eax, edi
// 00730e16  5f                   pop edi
// 00730e17  5e                   pop esi
// 00730e18  2bc1                 sub eax, ecx
// 00730e1a  5b                   pop ebx
// 00730e1b  83c408               add esp, 8
// 00730e1e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
