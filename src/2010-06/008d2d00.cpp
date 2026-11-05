// from server: 100% by auto
// roc 2010-06 008d2d00  unit: Ogre::VisualEngine  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d2d00
//
// 008d2d00  83ec08               sub esp, 8
// 008d2d03  8b542414             mov edx, dword ptr [esp + 0x14]
// 008d2d07  53                   push ebx
// 008d2d08  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008d2d0c  56                   push esi
// 008d2d0d  8b742418             mov esi, dword ptr [esp + 0x18]
// 008d2d11  57                   push edi
// 008d2d12  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008d2d16  32c0                 xor al, al
// 008d2d18  88442410             mov byte ptr [esp + 0x10], al
// 008d2d1c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008d2d20  8844240c             mov byte ptr [esp + 0xc], al
// 008d2d24  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008d2d28  50                   push eax
// 008d2d29  51                   push ecx
// 008d2d2a  52                   push edx
// 008d2d2b  57                   push edi
// 008d2d2c  56                   push esi
// 008d2d2d  53                   push ebx
// 008d2d2e  e80df3ffff           call 0x8d2040
// 008d2d33  2bf3                 sub esi, ebx
// 008d2d35  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d2d3a  f7ee                 imul esi
// 008d2d3c  c1fa02               sar edx, 2
// 008d2d3f  83c418               add esp, 0x18
// 008d2d42  8bc2                 mov eax, edx
// 008d2d44  c1e81f               shr eax, 0x1f
// 008d2d47  03c2                 add eax, edx
// 008d2d49  8d0440               lea eax, [eax + eax*2]
// 008d2d4c  8d04c7               lea eax, [edi + eax*8]
// 008d2d4f  5f                   pop edi
// 008d2d50  5e                   pop esi
// 008d2d51  5b                   pop ebx
// 008d2d52  83c408               add esp, 8
// 008d2d55  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
