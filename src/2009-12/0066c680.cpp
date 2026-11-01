// from server: 100% by auto
// roc 2009-12 0066c680  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::slot  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0066c680
//
// 0066c680  53                   push ebx
// 0066c681  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 0066c687  56                   push esi
// 0066c688  8bf1                 mov esi, ecx
// 0066c68a  8b06                 mov eax, dword ptr [esi]
// 0066c68c  57                   push edi
// 0066c68d  8b7e04               mov edi, dword ptr [esi + 4]
// 0066c690  85c0                 test eax, eax
// 0066c692  7508                 jne 0x66c69c
// 0066c694  ffd3                 call ebx
// 0066c696  8b06                 mov eax, dword ptr [esi]
// 0066c698  85c0                 test eax, eax
// 0066c69a  7404                 je 0x66c6a0
// 0066c69c  8b08                 mov ecx, dword ptr [eax]
// 0066c69e  eb02                 jmp 0x66c6a2
// 0066c6a0  33c9                 xor ecx, ecx
// 0066c6a2  85c0                 test eax, eax
// 0066c6a4  7404                 je 0x66c6aa
// 0066c6a6  8b00                 mov eax, dword ptr [eax]
// 0066c6a8  eb02                 jmp 0x66c6ac
// 0066c6aa  33c0                 xor eax, eax
// 0066c6ac  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0066c6af  034118               add eax, dword ptr [ecx + 0x18]
// 0066c6b2  394604               cmp dword ptr [esi + 4], eax
// 0066c6b5  7202                 jb 0x66c6b9
// 0066c6b7  ffd3                 call ebx
// 0066c6b9  8b36                 mov esi, dword ptr [esi]
// 0066c6bb  85f6                 test esi, esi
// 0066c6bd  7404                 je 0x66c6c3
// 0066c6bf  8b06                 mov eax, dword ptr [esi]
// 0066c6c1  eb02                 jmp 0x66c6c5
// 0066c6c3  33c0                 xor eax, eax
// 0066c6c5  397814               cmp dword ptr [eax + 0x14], edi
// 0066c6c8  770d                 ja 0x66c6d7
// 0066c6ca  85f6                 test esi, esi
// 0066c6cc  7404                 je 0x66c6d2
// 0066c6ce  8b06                 mov eax, dword ptr [esi]
// 0066c6d0  eb02                 jmp 0x66c6d4
// 0066c6d2  33c0                 xor eax, eax
// 0066c6d4  2b7814               sub edi, dword ptr [eax + 0x14]
// 0066c6d7  85f6                 test esi, esi
// 0066c6d9  740c                 je 0x66c6e7
// 0066c6db  8b36                 mov esi, dword ptr [esi]
// 0066c6dd  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0066c6e0  8b04b9               mov eax, dword ptr [ecx + edi*4]
// 0066c6e3  5f                   pop edi
// 0066c6e4  5e                   pop esi
// 0066c6e5  5b                   pop ebx
// 0066c6e6  c3                   ret 
// 0066c6e7  33c0                 xor eax, eax
// 0066c6e9  8b5010               mov edx, dword ptr [eax + 0x10]
// 0066c6ec  8b04ba               mov eax, dword ptr [edx + edi*4]
// 0066c6ef  5f                   pop edi
// 0066c6f0  5e                   pop esi
// 0066c6f1  5b                   pop ebx
// 0066c6f2  c3                   ret 
// standard library deque<string> (function ??D?$_Deque_const_iterator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$00@std@@QBEABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@XZ)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
