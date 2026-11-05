// from server: 100% by auto
// roc 2008-06 00496020  unit: RBX::Network::Players  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00496020
//
// 00496020  53                   push ebx
// 00496021  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00496027  56                   push esi
// 00496028  8bf1                 mov esi, ecx
// 0049602a  8b06                 mov eax, dword ptr [esi]
// 0049602c  57                   push edi
// 0049602d  8b7e04               mov edi, dword ptr [esi + 4]
// 00496030  85c0                 test eax, eax
// 00496032  7508                 jne 0x49603c
// 00496034  ffd3                 call ebx
// 00496036  8b06                 mov eax, dword ptr [esi]
// 00496038  85c0                 test eax, eax
// 0049603a  7404                 je 0x496040
// 0049603c  8b08                 mov ecx, dword ptr [eax]
// 0049603e  eb02                 jmp 0x496042
// 00496040  33c9                 xor ecx, ecx
// 00496042  85c0                 test eax, eax
// 00496044  7404                 je 0x49604a
// 00496046  8b00                 mov eax, dword ptr [eax]
// 00496048  eb02                 jmp 0x49604c
// 0049604a  33c0                 xor eax, eax
// 0049604c  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0049604f  034118               add eax, dword ptr [ecx + 0x18]
// 00496052  394604               cmp dword ptr [esi + 4], eax
// 00496055  7202                 jb 0x496059
// 00496057  ffd3                 call ebx
// 00496059  8b36                 mov esi, dword ptr [esi]
// 0049605b  85f6                 test esi, esi
// 0049605d  7404                 je 0x496063
// 0049605f  8b06                 mov eax, dword ptr [esi]
// 00496061  eb02                 jmp 0x496065
// 00496063  33c0                 xor eax, eax
// 00496065  397814               cmp dword ptr [eax + 0x14], edi
// 00496068  770d                 ja 0x496077
// 0049606a  85f6                 test esi, esi
// 0049606c  7404                 je 0x496072
// 0049606e  8b06                 mov eax, dword ptr [esi]
// 00496070  eb02                 jmp 0x496074
// 00496072  33c0                 xor eax, eax
// 00496074  2b7814               sub edi, dword ptr [eax + 0x14]
// 00496077  85f6                 test esi, esi
// 00496079  740c                 je 0x496087
// 0049607b  8b36                 mov esi, dword ptr [esi]
// 0049607d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00496080  8b04b9               mov eax, dword ptr [ecx + edi*4]
// 00496083  5f                   pop edi
// 00496084  5e                   pop esi
// 00496085  5b                   pop ebx
// 00496086  c3                   ret 
// 00496087  33c0                 xor eax, eax
// 00496089  8b5010               mov edx, dword ptr [eax + 0x10]
// 0049608c  8b04ba               mov eax, dword ptr [edx + edi*4]
// 0049608f  5f                   pop edi
// 00496090  5e                   pop esi
// 00496091  5b                   pop ebx
// 00496092  c3                   ret 
// standard library deque<string> (function ??D?$_Deque_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$00@std@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@XZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
