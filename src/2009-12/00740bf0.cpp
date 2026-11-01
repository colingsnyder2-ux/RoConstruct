// from server: 100% by auto
// roc 2009-12 00740bf0  unit: RBX::VirtualUser  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00740bf0
//
// 00740bf0  53                   push ebx
// 00740bf1  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00740bf7  55                   push ebp
// 00740bf8  56                   push esi
// 00740bf9  8bf1                 mov esi, ecx
// 00740bfb  8b4604               mov eax, dword ptr [esi + 4]
// 00740bfe  57                   push edi
// 00740bff  8bf8                 mov edi, eax
// 00740c01  83e001               and eax, 1
// 00740c04  8be8                 mov ebp, eax
// 00740c06  8b06                 mov eax, dword ptr [esi]
// 00740c08  d1ef                 shr edi, 1
// 00740c0a  85c0                 test eax, eax
// 00740c0c  7508                 jne 0x740c16
// 00740c0e  ffd3                 call ebx
// 00740c10  8b06                 mov eax, dword ptr [esi]
// 00740c12  85c0                 test eax, eax
// 00740c14  7404                 je 0x740c1a
// 00740c16  8b08                 mov ecx, dword ptr [eax]
// 00740c18  eb02                 jmp 0x740c1c
// 00740c1a  33c9                 xor ecx, ecx
// 00740c1c  85c0                 test eax, eax
// 00740c1e  7404                 je 0x740c24
// 00740c20  8b00                 mov eax, dword ptr [eax]
// 00740c22  eb02                 jmp 0x740c26
// 00740c24  33c0                 xor eax, eax
// 00740c26  8b401c               mov eax, dword ptr [eax + 0x1c]
// 00740c29  034118               add eax, dword ptr [ecx + 0x18]
// 00740c2c  394604               cmp dword ptr [esi + 4], eax
// 00740c2f  7202                 jb 0x740c33
// 00740c31  ffd3                 call ebx
// 00740c33  8b36                 mov esi, dword ptr [esi]
// 00740c35  85f6                 test esi, esi
// 00740c37  7404                 je 0x740c3d
// 00740c39  8b06                 mov eax, dword ptr [esi]
// 00740c3b  eb02                 jmp 0x740c3f
// 00740c3d  33c0                 xor eax, eax
// 00740c3f  397814               cmp dword ptr [eax + 0x14], edi
// 00740c42  770d                 ja 0x740c51
// 00740c44  85f6                 test esi, esi
// 00740c46  7404                 je 0x740c4c
// 00740c48  8b06                 mov eax, dword ptr [esi]
// 00740c4a  eb02                 jmp 0x740c4e
// 00740c4c  33c0                 xor eax, eax
// 00740c4e  2b7814               sub edi, dword ptr [eax + 0x14]
// 00740c51  85f6                 test esi, esi
// 00740c53  7410                 je 0x740c65
// 00740c55  8b36                 mov esi, dword ptr [esi]
// 00740c57  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00740c5a  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 00740c5d  5f                   pop edi
// 00740c5e  5e                   pop esi
// 00740c5f  8d04ea               lea eax, [edx + ebp*8]
// 00740c62  5d                   pop ebp
// 00740c63  5b                   pop ebx
// 00740c64  c3                   ret 
// 00740c65  33f6                 xor esi, esi
// 00740c67  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00740c6a  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 00740c6d  5f                   pop edi
// 00740c6e  5e                   pop esi
// 00740c6f  8d04ea               lea eax, [edx + ebp*8]
// 00740c72  5d                   pop ebp
// 00740c73  5b                   pop ebx
// 00740c74  c3                   ret 
// standard library deque<double> (function ??D?$_Deque_const_iterator@NV?$allocator@N@std@@$00@std@@QBEABNXZ)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;
