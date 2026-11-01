// from server: 100% by auto
// roc 2009-12 005dd440  unit: RBX::ImmediateMeshGenAdapter  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005dd440
//
// 005dd440  83ec08               sub esp, 8
// 005dd443  8b542414             mov edx, dword ptr [esp + 0x14]
// 005dd447  53                   push ebx
// 005dd448  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005dd44c  56                   push esi
// 005dd44d  8b742418             mov esi, dword ptr [esp + 0x18]
// 005dd451  57                   push edi
// 005dd452  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005dd456  32c0                 xor al, al
// 005dd458  88442410             mov byte ptr [esp + 0x10], al
// 005dd45c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005dd460  8844240c             mov byte ptr [esp + 0xc], al
// 005dd464  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005dd468  50                   push eax
// 005dd469  51                   push ecx
// 005dd46a  52                   push edx
// 005dd46b  57                   push edi
// 005dd46c  56                   push esi
// 005dd46d  53                   push ebx
// 005dd46e  e86dfdffff           call 0x5dd1e0
// 005dd473  2bf3                 sub esi, ebx
// 005dd475  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005dd47a  f7ee                 imul esi
// 005dd47c  c1fa02               sar edx, 2
// 005dd47f  8bc2                 mov eax, edx
// 005dd481  c1e81f               shr eax, 0x1f
// 005dd484  03c2                 add eax, edx
// 005dd486  8d0440               lea eax, [eax + eax*2]
// 005dd489  03c0                 add eax, eax
// 005dd48b  03c0                 add eax, eax
// 005dd48d  03c0                 add eax, eax
// 005dd48f  83c418               add esp, 0x18
// 005dd492  8bc8                 mov ecx, eax
// 005dd494  8bc7                 mov eax, edi
// 005dd496  5f                   pop edi
// 005dd497  5e                   pop esi
// 005dd498  2bc1                 sub eax, ecx
// 005dd49a  5b                   pop ebx
// 005dd49b  83c408               add esp, 8
// 005dd49e  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@@std@@YAPAUE@@PAU1@00Urandom_access_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
