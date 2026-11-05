// from server: 100% by auto
// roc 2009-12 0058afb0  unit: RBX::BeveledBlockBuilder  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058afb0
//
// 0058afb0  83ec08               sub esp, 8
// 0058afb3  8b542414             mov edx, dword ptr [esp + 0x14]
// 0058afb7  53                   push ebx
// 0058afb8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0058afbc  56                   push esi
// 0058afbd  8b742418             mov esi, dword ptr [esp + 0x18]
// 0058afc1  57                   push edi
// 0058afc2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058afc6  32c0                 xor al, al
// 0058afc8  88442410             mov byte ptr [esp + 0x10], al
// 0058afcc  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058afd0  8844240c             mov byte ptr [esp + 0xc], al
// 0058afd4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0058afd8  50                   push eax
// 0058afd9  51                   push ecx
// 0058afda  52                   push edx
// 0058afdb  57                   push edi
// 0058afdc  56                   push esi
// 0058afdd  53                   push ebx
// 0058afde  e82de2ffff           call 0x589210
// 0058afe3  2bf3                 sub esi, ebx
// 0058afe5  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0058afea  f7ee                 imul esi
// 0058afec  c1fa02               sar edx, 2
// 0058afef  8bc2                 mov eax, edx
// 0058aff1  c1e81f               shr eax, 0x1f
// 0058aff4  03c2                 add eax, edx
// 0058aff6  8d0440               lea eax, [eax + eax*2]
// 0058aff9  03c0                 add eax, eax
// 0058affb  03c0                 add eax, eax
// 0058affd  03c0                 add eax, eax
// 0058afff  83c418               add esp, 0x18
// 0058b002  8bc8                 mov ecx, eax
// 0058b004  8bc7                 mov eax, edi
// 0058b006  5f                   pop edi
// 0058b007  5e                   pop esi
// 0058b008  2bc1                 sub eax, ecx
// 0058b00a  5b                   pop ebx
// 0058b00b  83c408               add esp, 8
// 0058b00e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
