// from server: 100% by auto
// roc 2010-06 00787070  unit: RBX::HUMAN::GettingUp  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00787070
//
// 00787070  83ec08               sub esp, 8
// 00787073  8b542414             mov edx, dword ptr [esp + 0x14]
// 00787077  53                   push ebx
// 00787078  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0078707c  56                   push esi
// 0078707d  8b742418             mov esi, dword ptr [esp + 0x18]
// 00787081  57                   push edi
// 00787082  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00787086  32c0                 xor al, al
// 00787088  88442410             mov byte ptr [esp + 0x10], al
// 0078708c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00787090  8844240c             mov byte ptr [esp + 0xc], al
// 00787094  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00787098  50                   push eax
// 00787099  51                   push ecx
// 0078709a  52                   push edx
// 0078709b  57                   push edi
// 0078709c  56                   push esi
// 0078709d  53                   push ebx
// 0078709e  e89df2ffff           call 0x786340
// 007870a3  2bf3                 sub esi, ebx
// 007870a5  b867666666           mov eax, 0x66666667
// 007870aa  f7ee                 imul esi
// 007870ac  c1fa03               sar edx, 3
// 007870af  8bc2                 mov eax, edx
// 007870b1  c1e81f               shr eax, 0x1f
// 007870b4  03c2                 add eax, edx
// 007870b6  8d0480               lea eax, [eax + eax*4]
// 007870b9  03c0                 add eax, eax
// 007870bb  03c0                 add eax, eax
// 007870bd  83c418               add esp, 0x18
// 007870c0  8bc8                 mov ecx, eax
// 007870c2  8bc7                 mov eax, edi
// 007870c4  5f                   pop edi
// 007870c5  5e                   pop esi
// 007870c6  2bc1                 sub eax, ecx
// 007870c8  5b                   pop ebx
// 007870c9  83c408               add esp, 8
// 007870cc  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
