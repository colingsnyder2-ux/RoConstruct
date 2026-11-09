// from server: 100% by auto
// roc 2009-06 00496820  unit: Ogre::TwoDManager  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00496820
//
// 00496820  53                   push ebx
// 00496821  8b1dace98900         mov ebx, dword ptr [0x89e9ac]
// 00496827  55                   push ebp
// 00496828  56                   push esi
// 00496829  8bf1                 mov esi, ecx
// 0049682b  8b4604               mov eax, dword ptr [esi + 4]
// 0049682e  57                   push edi
// 0049682f  8bf8                 mov edi, eax
// 00496831  83e003               and eax, 3
// 00496834  8be8                 mov ebp, eax
// 00496836  8b06                 mov eax, dword ptr [esi]
// 00496838  c1ef02               shr edi, 2
// 0049683b  85c0                 test eax, eax
// 0049683d  7508                 jne 0x496847
// 0049683f  ffd3                 call ebx
// 00496841  8b06                 mov eax, dword ptr [esi]
// 00496843  85c0                 test eax, eax
// 00496845  7404                 je 0x49684b
// 00496847  8b08                 mov ecx, dword ptr [eax]
// 00496849  eb02                 jmp 0x49684d
// 0049684b  33c9                 xor ecx, ecx
// 0049684d  85c0                 test eax, eax
// 0049684f  7404                 je 0x496855
// 00496851  8b00                 mov eax, dword ptr [eax]
// 00496853  eb02                 jmp 0x496857
// 00496855  33c0                 xor eax, eax
// 00496857  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0049685a  034118               add eax, dword ptr [ecx + 0x18]
// 0049685d  394604               cmp dword ptr [esi + 4], eax
// 00496860  7202                 jb 0x496864
// 00496862  ffd3                 call ebx
// 00496864  8b36                 mov esi, dword ptr [esi]
// 00496866  85f6                 test esi, esi
// 00496868  7404                 je 0x49686e
// 0049686a  8b06                 mov eax, dword ptr [esi]
// 0049686c  eb02                 jmp 0x496870
// 0049686e  33c0                 xor eax, eax
// 00496870  397814               cmp dword ptr [eax + 0x14], edi
// 00496873  770d                 ja 0x496882
// 00496875  85f6                 test esi, esi
// 00496877  7404                 je 0x49687d
// 00496879  8b06                 mov eax, dword ptr [esi]
// 0049687b  eb02                 jmp 0x49687f
// 0049687d  33c0                 xor eax, eax
// 0049687f  2b7814               sub edi, dword ptr [eax + 0x14]
// 00496882  85f6                 test esi, esi
// 00496884  7410                 je 0x496896
// 00496886  8b36                 mov esi, dword ptr [esi]
// 00496888  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0049688b  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0049688e  5f                   pop edi
// 0049688f  5e                   pop esi
// 00496890  8d04aa               lea eax, [edx + ebp*4]
// 00496893  5d                   pop ebp
// 00496894  5b                   pop ebx
// 00496895  c3                   ret 
// 00496896  33f6                 xor esi, esi
// 00496898  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0049689b  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0049689e  5f                   pop edi
// 0049689f  5e                   pop esi
// 004968a0  8d04aa               lea eax, [edx + ebp*4]
// 004968a3  5d                   pop ebp
// 004968a4  5b                   pop ebx
// 004968a5  c3                   ret 
// standard library deque<ptr> (function ??D?$_Deque_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@$00@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
