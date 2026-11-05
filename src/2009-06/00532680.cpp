// from server: 100% by auto
// roc 2009-06 00532680  unit: RBX::BeveledBlockBuilder  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00532680
//
// 00532680  83ec08               sub esp, 8
// 00532683  8b542414             mov edx, dword ptr [esp + 0x14]
// 00532687  53                   push ebx
// 00532688  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0053268c  56                   push esi
// 0053268d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00532691  57                   push edi
// 00532692  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00532696  32c0                 xor al, al
// 00532698  88442410             mov byte ptr [esp + 0x10], al
// 0053269c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005326a0  8844240c             mov byte ptr [esp + 0xc], al
// 005326a4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005326a8  50                   push eax
// 005326a9  51                   push ecx
// 005326aa  52                   push edx
// 005326ab  57                   push edi
// 005326ac  56                   push esi
// 005326ad  53                   push ebx
// 005326ae  e8dde4ffff           call 0x530b90
// 005326b3  2bf3                 sub esi, ebx
// 005326b5  b867666666           mov eax, 0x66666667
// 005326ba  f7ee                 imul esi
// 005326bc  c1fa03               sar edx, 3
// 005326bf  83c418               add esp, 0x18
// 005326c2  8bc2                 mov eax, edx
// 005326c4  c1e81f               shr eax, 0x1f
// 005326c7  03c2                 add eax, edx
// 005326c9  8d0480               lea eax, [eax + eax*4]
// 005326cc  8d0487               lea eax, [edi + eax*4]
// 005326cf  5f                   pop edi
// 005326d0  5e                   pop esi
// 005326d1  5b                   pop ebx
// 005326d2  83c408               add esp, 8
// 005326d5  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
