// from server: 100% by auto
// roc 2010-06 005d3710  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::slot  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005d3710
//
// 005d3710  53                   push ebx
// 005d3711  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 005d3717  56                   push esi
// 005d3718  8bf1                 mov esi, ecx
// 005d371a  8b06                 mov eax, dword ptr [esi]
// 005d371c  57                   push edi
// 005d371d  8b7e04               mov edi, dword ptr [esi + 4]
// 005d3720  85c0                 test eax, eax
// 005d3722  7508                 jne 0x5d372c
// 005d3724  ffd3                 call ebx
// 005d3726  8b06                 mov eax, dword ptr [esi]
// 005d3728  85c0                 test eax, eax
// 005d372a  7404                 je 0x5d3730
// 005d372c  8b08                 mov ecx, dword ptr [eax]
// 005d372e  eb02                 jmp 0x5d3732
// 005d3730  33c9                 xor ecx, ecx
// 005d3732  85c0                 test eax, eax
// 005d3734  7404                 je 0x5d373a
// 005d3736  8b00                 mov eax, dword ptr [eax]
// 005d3738  eb02                 jmp 0x5d373c
// 005d373a  33c0                 xor eax, eax
// 005d373c  8b401c               mov eax, dword ptr [eax + 0x1c]
// 005d373f  034118               add eax, dword ptr [ecx + 0x18]
// 005d3742  394604               cmp dword ptr [esi + 4], eax
// 005d3745  7202                 jb 0x5d3749
// 005d3747  ffd3                 call ebx
// 005d3749  8b36                 mov esi, dword ptr [esi]
// 005d374b  85f6                 test esi, esi
// 005d374d  7404                 je 0x5d3753
// 005d374f  8b06                 mov eax, dword ptr [esi]
// 005d3751  eb02                 jmp 0x5d3755
// 005d3753  33c0                 xor eax, eax
// 005d3755  397814               cmp dword ptr [eax + 0x14], edi
// 005d3758  770d                 ja 0x5d3767
// 005d375a  85f6                 test esi, esi
// 005d375c  7404                 je 0x5d3762
// 005d375e  8b06                 mov eax, dword ptr [esi]
// 005d3760  eb02                 jmp 0x5d3764
// 005d3762  33c0                 xor eax, eax
// 005d3764  2b7814               sub edi, dword ptr [eax + 0x14]
// 005d3767  85f6                 test esi, esi
// 005d3769  740c                 je 0x5d3777
// 005d376b  8b36                 mov esi, dword ptr [esi]
// 005d376d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005d3770  8b04b9               mov eax, dword ptr [ecx + edi*4]
// 005d3773  5f                   pop edi
// 005d3774  5e                   pop esi
// 005d3775  5b                   pop ebx
// 005d3776  c3                   ret 
// 005d3777  33c0                 xor eax, eax
// 005d3779  8b5010               mov edx, dword ptr [eax + 0x10]
// 005d377c  8b04ba               mov eax, dword ptr [edx + edi*4]
// 005d377f  5f                   pop edi
// 005d3780  5e                   pop esi
// 005d3781  5b                   pop ebx
// 005d3782  c3                   ret 
// standard library deque<string> (function ??D?$_Deque_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$00@std@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@XZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
