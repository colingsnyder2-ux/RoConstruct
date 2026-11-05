// from server: 100% by auto
// roc 2008-06 0063b400  unit: RBX::VBodyGyro::?$BoundPropGetSet  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063b400
//
// 0063b400  53                   push ebx
// 0063b401  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0063b407  55                   push ebp
// 0063b408  56                   push esi
// 0063b409  8bf1                 mov esi, ecx
// 0063b40b  8b4604               mov eax, dword ptr [esi + 4]
// 0063b40e  57                   push edi
// 0063b40f  8bf8                 mov edi, eax
// 0063b411  83e001               and eax, 1
// 0063b414  8be8                 mov ebp, eax
// 0063b416  8b06                 mov eax, dword ptr [esi]
// 0063b418  d1ef                 shr edi, 1
// 0063b41a  85c0                 test eax, eax
// 0063b41c  7508                 jne 0x63b426
// 0063b41e  ffd3                 call ebx
// 0063b420  8b06                 mov eax, dword ptr [esi]
// 0063b422  85c0                 test eax, eax
// 0063b424  7404                 je 0x63b42a
// 0063b426  8b08                 mov ecx, dword ptr [eax]
// 0063b428  eb02                 jmp 0x63b42c
// 0063b42a  33c9                 xor ecx, ecx
// 0063b42c  85c0                 test eax, eax
// 0063b42e  7404                 je 0x63b434
// 0063b430  8b00                 mov eax, dword ptr [eax]
// 0063b432  eb02                 jmp 0x63b436
// 0063b434  33c0                 xor eax, eax
// 0063b436  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0063b439  034118               add eax, dword ptr [ecx + 0x18]
// 0063b43c  394604               cmp dword ptr [esi + 4], eax
// 0063b43f  7202                 jb 0x63b443
// 0063b441  ffd3                 call ebx
// 0063b443  8b36                 mov esi, dword ptr [esi]
// 0063b445  85f6                 test esi, esi
// 0063b447  7404                 je 0x63b44d
// 0063b449  8b06                 mov eax, dword ptr [esi]
// 0063b44b  eb02                 jmp 0x63b44f
// 0063b44d  33c0                 xor eax, eax
// 0063b44f  397814               cmp dword ptr [eax + 0x14], edi
// 0063b452  770d                 ja 0x63b461
// 0063b454  85f6                 test esi, esi
// 0063b456  7404                 je 0x63b45c
// 0063b458  8b06                 mov eax, dword ptr [esi]
// 0063b45a  eb02                 jmp 0x63b45e
// 0063b45c  33c0                 xor eax, eax
// 0063b45e  2b7814               sub edi, dword ptr [eax + 0x14]
// 0063b461  85f6                 test esi, esi
// 0063b463  7410                 je 0x63b475
// 0063b465  8b36                 mov esi, dword ptr [esi]
// 0063b467  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0063b46a  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0063b46d  5f                   pop edi
// 0063b46e  5e                   pop esi
// 0063b46f  8d04ea               lea eax, [edx + ebp*8]
// 0063b472  5d                   pop ebp
// 0063b473  5b                   pop ebx
// 0063b474  c3                   ret 
// 0063b475  33f6                 xor esi, esi
// 0063b477  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0063b47a  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0063b47d  5f                   pop edi
// 0063b47e  5e                   pop esi
// 0063b47f  8d04ea               lea eax, [edx + ebp*8]
// 0063b482  5d                   pop ebp
// 0063b483  5b                   pop ebx
// 0063b484  c3                   ret 
// standard library deque<double> (function ??D?$_Deque_const_iterator@NV?$allocator@N@std@@$00@std@@QBEABNXZ)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;
