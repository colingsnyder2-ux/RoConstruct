// from server: 100% by auto
// roc 2010-06 007310a0  unit: lua_exception  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007310a0
//
// 007310a0  83ec08               sub esp, 8
// 007310a3  8b542414             mov edx, dword ptr [esp + 0x14]
// 007310a7  53                   push ebx
// 007310a8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007310ac  56                   push esi
// 007310ad  8b742418             mov esi, dword ptr [esp + 0x18]
// 007310b1  57                   push edi
// 007310b2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007310b6  32c0                 xor al, al
// 007310b8  88442410             mov byte ptr [esp + 0x10], al
// 007310bc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007310c0  8844240c             mov byte ptr [esp + 0xc], al
// 007310c4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007310c8  50                   push eax
// 007310c9  51                   push ecx
// 007310ca  52                   push edx
// 007310cb  57                   push edi
// 007310cc  56                   push esi
// 007310cd  53                   push ebx
// 007310ce  e80df7ffff           call 0x7307e0
// 007310d3  2bf3                 sub esi, ebx
// 007310d5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 007310da  f7ee                 imul esi
// 007310dc  c1fa02               sar edx, 2
// 007310df  83c418               add esp, 0x18
// 007310e2  8bc2                 mov eax, edx
// 007310e4  c1e81f               shr eax, 0x1f
// 007310e7  03c2                 add eax, edx
// 007310e9  8d0440               lea eax, [eax + eax*2]
// 007310ec  8d04c7               lea eax, [edi + eax*8]
// 007310ef  5f                   pop edi
// 007310f0  5e                   pop esi
// 007310f1  5b                   pop ebx
// 007310f2  83c408               add esp, 8
// 007310f5  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
