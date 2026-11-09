// from server: 100% by auto
// roc 2010-06 00731100  unit: lua_exception  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00731100
//
// 00731100  83ec08               sub esp, 8
// 00731103  8b542414             mov edx, dword ptr [esp + 0x14]
// 00731107  53                   push ebx
// 00731108  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0073110c  56                   push esi
// 0073110d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00731111  57                   push edi
// 00731112  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00731116  32c0                 xor al, al
// 00731118  88442410             mov byte ptr [esp + 0x10], al
// 0073111c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00731120  8844240c             mov byte ptr [esp + 0xc], al
// 00731124  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00731128  50                   push eax
// 00731129  51                   push ecx
// 0073112a  52                   push edx
// 0073112b  57                   push edi
// 0073112c  56                   push esi
// 0073112d  53                   push ebx
// 0073112e  e83df7ffff           call 0x730870
// 00731133  2bf3                 sub esi, ebx
// 00731135  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0073113a  f7ee                 imul esi
// 0073113c  c1fa02               sar edx, 2
// 0073113f  83c418               add esp, 0x18
// 00731142  8bc2                 mov eax, edx
// 00731144  c1e81f               shr eax, 0x1f
// 00731147  03c2                 add eax, edx
// 00731149  8d0440               lea eax, [eax + eax*2]
// 0073114c  8d04c7               lea eax, [edi + eax*8]
// 0073114f  5f                   pop edi
// 00731150  5e                   pop esi
// 00731151  5b                   pop ebx
// 00731152  83c408               add esp, 8
// 00731155  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
