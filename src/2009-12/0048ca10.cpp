// from server: 100% by auto
// roc 2009-12 0048ca10  unit: G3D::Shader  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048ca10
//
// 0048ca10  83ec08               sub esp, 8
// 0048ca13  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048ca17  53                   push ebx
// 0048ca18  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0048ca1c  56                   push esi
// 0048ca1d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0048ca21  57                   push edi
// 0048ca22  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0048ca26  32c0                 xor al, al
// 0048ca28  88442410             mov byte ptr [esp + 0x10], al
// 0048ca2c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0048ca30  8844240c             mov byte ptr [esp + 0xc], al
// 0048ca34  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0048ca38  50                   push eax
// 0048ca39  51                   push ecx
// 0048ca3a  52                   push edx
// 0048ca3b  57                   push edi
// 0048ca3c  56                   push esi
// 0048ca3d  53                   push ebx
// 0048ca3e  e80df3ffff           call 0x48bd50
// 0048ca43  2bf3                 sub esi, ebx
// 0048ca45  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048ca4a  f7ee                 imul esi
// 0048ca4c  c1fa02               sar edx, 2
// 0048ca4f  83c418               add esp, 0x18
// 0048ca52  8bc2                 mov eax, edx
// 0048ca54  c1e81f               shr eax, 0x1f
// 0048ca57  03c2                 add eax, edx
// 0048ca59  8d0440               lea eax, [eax + eax*2]
// 0048ca5c  8d04c7               lea eax, [edi + eax*8]
// 0048ca5f  5f                   pop edi
// 0048ca60  5e                   pop esi
// 0048ca61  5b                   pop ebx
// 0048ca62  83c408               add esp, 8
// 0048ca65  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
