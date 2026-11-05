// from server: 100% by auto
// roc 2008-06 00620d60  unit: RBX::Lua::VThreadRef::?$sp_counted_impl_p  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00620d60
//
// 00620d60  83ec08               sub esp, 8
// 00620d63  8b542414             mov edx, dword ptr [esp + 0x14]
// 00620d67  53                   push ebx
// 00620d68  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00620d6c  56                   push esi
// 00620d6d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00620d71  57                   push edi
// 00620d72  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00620d76  32c0                 xor al, al
// 00620d78  88442410             mov byte ptr [esp + 0x10], al
// 00620d7c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00620d80  8844240c             mov byte ptr [esp + 0xc], al
// 00620d84  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00620d88  50                   push eax
// 00620d89  51                   push ecx
// 00620d8a  52                   push edx
// 00620d8b  57                   push edi
// 00620d8c  56                   push esi
// 00620d8d  53                   push ebx
// 00620d8e  e8edfcffff           call 0x620a80
// 00620d93  2bf3                 sub esi, ebx
// 00620d95  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00620d9a  f7ee                 imul esi
// 00620d9c  c1fa02               sar edx, 2
// 00620d9f  83c418               add esp, 0x18
// 00620da2  8bc2                 mov eax, edx
// 00620da4  c1e81f               shr eax, 0x1f
// 00620da7  03c2                 add eax, edx
// 00620da9  8d0440               lea eax, [eax + eax*2]
// 00620dac  8d04c7               lea eax, [edi + eax*8]
// 00620daf  5f                   pop edi
// 00620db0  5e                   pop esi
// 00620db1  5b                   pop ebx
// 00620db2  83c408               add esp, 8
// 00620db5  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
