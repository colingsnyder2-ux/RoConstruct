// from server: 100% by auto
// roc 2010-06 006f3d60  unit: RBX::VStudioTool::?$EventDesc  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006f3d60
//
// 006f3d60  53                   push ebx
// 006f3d61  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 006f3d67  55                   push ebp
// 006f3d68  56                   push esi
// 006f3d69  8bf1                 mov esi, ecx
// 006f3d6b  8b4604               mov eax, dword ptr [esi + 4]
// 006f3d6e  57                   push edi
// 006f3d6f  8bf8                 mov edi, eax
// 006f3d71  83e001               and eax, 1
// 006f3d74  8be8                 mov ebp, eax
// 006f3d76  8b06                 mov eax, dword ptr [esi]
// 006f3d78  d1ef                 shr edi, 1
// 006f3d7a  85c0                 test eax, eax
// 006f3d7c  7508                 jne 0x6f3d86
// 006f3d7e  ffd3                 call ebx
// 006f3d80  8b06                 mov eax, dword ptr [esi]
// 006f3d82  85c0                 test eax, eax
// 006f3d84  7404                 je 0x6f3d8a
// 006f3d86  8b08                 mov ecx, dword ptr [eax]
// 006f3d88  eb02                 jmp 0x6f3d8c
// 006f3d8a  33c9                 xor ecx, ecx
// 006f3d8c  85c0                 test eax, eax
// 006f3d8e  7404                 je 0x6f3d94
// 006f3d90  8b00                 mov eax, dword ptr [eax]
// 006f3d92  eb02                 jmp 0x6f3d96
// 006f3d94  33c0                 xor eax, eax
// 006f3d96  8b401c               mov eax, dword ptr [eax + 0x1c]
// 006f3d99  034118               add eax, dword ptr [ecx + 0x18]
// 006f3d9c  394604               cmp dword ptr [esi + 4], eax
// 006f3d9f  7202                 jb 0x6f3da3
// 006f3da1  ffd3                 call ebx
// 006f3da3  8b36                 mov esi, dword ptr [esi]
// 006f3da5  85f6                 test esi, esi
// 006f3da7  7404                 je 0x6f3dad
// 006f3da9  8b06                 mov eax, dword ptr [esi]
// 006f3dab  eb02                 jmp 0x6f3daf
// 006f3dad  33c0                 xor eax, eax
// 006f3daf  397814               cmp dword ptr [eax + 0x14], edi
// 006f3db2  770d                 ja 0x6f3dc1
// 006f3db4  85f6                 test esi, esi
// 006f3db6  7404                 je 0x6f3dbc
// 006f3db8  8b06                 mov eax, dword ptr [esi]
// 006f3dba  eb02                 jmp 0x6f3dbe
// 006f3dbc  33c0                 xor eax, eax
// 006f3dbe  2b7814               sub edi, dword ptr [eax + 0x14]
// 006f3dc1  85f6                 test esi, esi
// 006f3dc3  7410                 je 0x6f3dd5
// 006f3dc5  8b36                 mov esi, dword ptr [esi]
// 006f3dc7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006f3dca  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 006f3dcd  5f                   pop edi
// 006f3dce  5e                   pop esi
// 006f3dcf  8d04ea               lea eax, [edx + ebp*8]
// 006f3dd2  5d                   pop ebp
// 006f3dd3  5b                   pop ebx
// 006f3dd4  c3                   ret 
// 006f3dd5  33f6                 xor esi, esi
// 006f3dd7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006f3dda  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 006f3ddd  5f                   pop edi
// 006f3dde  5e                   pop esi
// 006f3ddf  8d04ea               lea eax, [edx + ebp*8]
// 006f3de2  5d                   pop ebp
// 006f3de3  5b                   pop ebx
// 006f3de4  c3                   ret 
// standard library deque<double> (function ??D?$_Deque_const_iterator@NV?$allocator@N@std@@$00@std@@QBEABNXZ)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;
