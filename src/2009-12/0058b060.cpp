// from server: 100% by auto
// roc 2009-12 0058b060  unit: RBX::BeveledBlockBuilder  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0058b060
//
// 0058b060  83ec08               sub esp, 8
// 0058b063  8b542414             mov edx, dword ptr [esp + 0x14]
// 0058b067  53                   push ebx
// 0058b068  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0058b06c  56                   push esi
// 0058b06d  8b742418             mov esi, dword ptr [esp + 0x18]
// 0058b071  57                   push edi
// 0058b072  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0058b076  32c0                 xor al, al
// 0058b078  88442410             mov byte ptr [esp + 0x10], al
// 0058b07c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0058b080  8844240c             mov byte ptr [esp + 0xc], al
// 0058b084  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0058b088  50                   push eax
// 0058b089  51                   push ecx
// 0058b08a  52                   push edx
// 0058b08b  57                   push edi
// 0058b08c  56                   push esi
// 0058b08d  53                   push ebx
// 0058b08e  e83de1ffff           call 0x5891d0
// 0058b093  2bf3                 sub esi, ebx
// 0058b095  b867666666           mov eax, 0x66666667
// 0058b09a  f7ee                 imul esi
// 0058b09c  c1fa03               sar edx, 3
// 0058b09f  83c418               add esp, 0x18
// 0058b0a2  8bc2                 mov eax, edx
// 0058b0a4  c1e81f               shr eax, 0x1f
// 0058b0a7  03c2                 add eax, edx
// 0058b0a9  8d0480               lea eax, [eax + eax*4]
// 0058b0ac  8d0487               lea eax, [edi + eax*4]
// 0058b0af  5f                   pop edi
// 0058b0b0  5e                   pop esi
// 0058b0b1  5b                   pop ebx
// 0058b0b2  83c408               add esp, 8
// 0058b0b5  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
