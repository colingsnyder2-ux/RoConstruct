// from server: 100% by auto
// roc 2009-06 005325d0  unit: RBX::BeveledBlockBuilder  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005325d0
//
// 005325d0  83ec08               sub esp, 8
// 005325d3  8b542414             mov edx, dword ptr [esp + 0x14]
// 005325d7  53                   push ebx
// 005325d8  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005325dc  56                   push esi
// 005325dd  8b742418             mov esi, dword ptr [esp + 0x18]
// 005325e1  57                   push edi
// 005325e2  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005325e6  32c0                 xor al, al
// 005325e8  88442410             mov byte ptr [esp + 0x10], al
// 005325ec  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005325f0  8844240c             mov byte ptr [esp + 0xc], al
// 005325f4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005325f8  50                   push eax
// 005325f9  51                   push ecx
// 005325fa  52                   push edx
// 005325fb  57                   push edi
// 005325fc  56                   push esi
// 005325fd  53                   push ebx
// 005325fe  e8cde5ffff           call 0x530bd0
// 00532603  2bf3                 sub esi, ebx
// 00532605  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053260a  f7ee                 imul esi
// 0053260c  c1fa02               sar edx, 2
// 0053260f  8bc2                 mov eax, edx
// 00532611  c1e81f               shr eax, 0x1f
// 00532614  03c2                 add eax, edx
// 00532616  8d0440               lea eax, [eax + eax*2]
// 00532619  03c0                 add eax, eax
// 0053261b  03c0                 add eax, eax
// 0053261d  03c0                 add eax, eax
// 0053261f  83c418               add esp, 0x18
// 00532622  8bc8                 mov ecx, eax
// 00532624  8bc7                 mov eax, edi
// 00532626  5f                   pop edi
// 00532627  5e                   pop esi
// 00532628  2bc1                 sub eax, ecx
// 0053262a  5b                   pop ebx
// 0053262b  83c408               add esp, 8
// 0053262e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
