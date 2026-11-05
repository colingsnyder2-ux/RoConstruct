// from server: 100% by auto
// roc 2009-06 00409650  unit: std::logic_error  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00409650
//
// 00409650  53                   push ebx
// 00409651  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00409657  55                   push ebp
// 00409658  56                   push esi
// 00409659  8bf1                 mov esi, ecx
// 0040965b  8b4604               mov eax, dword ptr [esi + 4]
// 0040965e  57                   push edi
// 0040965f  8bf8                 mov edi, eax
// 00409661  83e001               and eax, 1
// 00409664  8be8                 mov ebp, eax
// 00409666  8b06                 mov eax, dword ptr [esi]
// 00409668  d1ef                 shr edi, 1
// 0040966a  85c0                 test eax, eax
// 0040966c  7508                 jne 0x409676
// 0040966e  ffd3                 call ebx
// 00409670  8b06                 mov eax, dword ptr [esi]
// 00409672  85c0                 test eax, eax
// 00409674  7404                 je 0x40967a
// 00409676  8b08                 mov ecx, dword ptr [eax]
// 00409678  eb02                 jmp 0x40967c
// 0040967a  33c9                 xor ecx, ecx
// 0040967c  85c0                 test eax, eax
// 0040967e  7404                 je 0x409684
// 00409680  8b00                 mov eax, dword ptr [eax]
// 00409682  eb02                 jmp 0x409686
// 00409684  33c0                 xor eax, eax
// 00409686  8b401c               mov eax, dword ptr [eax + 0x1c]
// 00409689  034118               add eax, dword ptr [ecx + 0x18]
// 0040968c  394604               cmp dword ptr [esi + 4], eax
// 0040968f  7202                 jb 0x409693
// 00409691  ffd3                 call ebx
// 00409693  8b36                 mov esi, dword ptr [esi]
// 00409695  85f6                 test esi, esi
// 00409697  7404                 je 0x40969d
// 00409699  8b06                 mov eax, dword ptr [esi]
// 0040969b  eb02                 jmp 0x40969f
// 0040969d  33c0                 xor eax, eax
// 0040969f  397814               cmp dword ptr [eax + 0x14], edi
// 004096a2  770d                 ja 0x4096b1
// 004096a4  85f6                 test esi, esi
// 004096a6  7404                 je 0x4096ac
// 004096a8  8b06                 mov eax, dword ptr [esi]
// 004096aa  eb02                 jmp 0x4096ae
// 004096ac  33c0                 xor eax, eax
// 004096ae  2b7814               sub edi, dword ptr [eax + 0x14]
// 004096b1  85f6                 test esi, esi
// 004096b3  7410                 je 0x4096c5
// 004096b5  8b36                 mov esi, dword ptr [esi]
// 004096b7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004096ba  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 004096bd  5f                   pop edi
// 004096be  5e                   pop esi
// 004096bf  8d04ea               lea eax, [edx + ebp*8]
// 004096c2  5d                   pop ebp
// 004096c3  5b                   pop ebx
// 004096c4  c3                   ret 
// 004096c5  33f6                 xor esi, esi
// 004096c7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 004096ca  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 004096cd  5f                   pop edi
// 004096ce  5e                   pop esi
// 004096cf  8d04ea               lea eax, [edx + ebp*8]
// 004096d2  5d                   pop ebp
// 004096d3  5b                   pop ebx
// 004096d4  c3                   ret 
// standard library deque<double> (function ??D?$_Deque_const_iterator@NV?$allocator@N@std@@$00@std@@QBEABNXZ)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;
