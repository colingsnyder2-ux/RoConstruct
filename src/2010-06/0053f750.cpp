// from server: 100% by auto
// roc 2010-06 0053f750  unit: RBX::SceneManager  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053f750
//
// 0053f750  53                   push ebx
// 0053f751  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 0053f757  55                   push ebp
// 0053f758  56                   push esi
// 0053f759  8bf1                 mov esi, ecx
// 0053f75b  8b4604               mov eax, dword ptr [esi + 4]
// 0053f75e  57                   push edi
// 0053f75f  8bf8                 mov edi, eax
// 0053f761  83e003               and eax, 3
// 0053f764  8be8                 mov ebp, eax
// 0053f766  8b06                 mov eax, dword ptr [esi]
// 0053f768  c1ef02               shr edi, 2
// 0053f76b  85c0                 test eax, eax
// 0053f76d  7508                 jne 0x53f777
// 0053f76f  ffd3                 call ebx
// 0053f771  8b06                 mov eax, dword ptr [esi]
// 0053f773  85c0                 test eax, eax
// 0053f775  7404                 je 0x53f77b
// 0053f777  8b08                 mov ecx, dword ptr [eax]
// 0053f779  eb02                 jmp 0x53f77d
// 0053f77b  33c9                 xor ecx, ecx
// 0053f77d  85c0                 test eax, eax
// 0053f77f  7404                 je 0x53f785
// 0053f781  8b00                 mov eax, dword ptr [eax]
// 0053f783  eb02                 jmp 0x53f787
// 0053f785  33c0                 xor eax, eax
// 0053f787  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0053f78a  034118               add eax, dword ptr [ecx + 0x18]
// 0053f78d  394604               cmp dword ptr [esi + 4], eax
// 0053f790  7202                 jb 0x53f794
// 0053f792  ffd3                 call ebx
// 0053f794  8b36                 mov esi, dword ptr [esi]
// 0053f796  85f6                 test esi, esi
// 0053f798  7404                 je 0x53f79e
// 0053f79a  8b06                 mov eax, dword ptr [esi]
// 0053f79c  eb02                 jmp 0x53f7a0
// 0053f79e  33c0                 xor eax, eax
// 0053f7a0  397814               cmp dword ptr [eax + 0x14], edi
// 0053f7a3  770d                 ja 0x53f7b2
// 0053f7a5  85f6                 test esi, esi
// 0053f7a7  7404                 je 0x53f7ad
// 0053f7a9  8b06                 mov eax, dword ptr [esi]
// 0053f7ab  eb02                 jmp 0x53f7af
// 0053f7ad  33c0                 xor eax, eax
// 0053f7af  2b7814               sub edi, dword ptr [eax + 0x14]
// 0053f7b2  85f6                 test esi, esi
// 0053f7b4  7410                 je 0x53f7c6
// 0053f7b6  8b36                 mov esi, dword ptr [esi]
// 0053f7b8  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0053f7bb  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0053f7be  5f                   pop edi
// 0053f7bf  5e                   pop esi
// 0053f7c0  8d04aa               lea eax, [edx + ebp*4]
// 0053f7c3  5d                   pop ebp
// 0053f7c4  5b                   pop ebx
// 0053f7c5  c3                   ret 
// 0053f7c6  33f6                 xor esi, esi
// 0053f7c8  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0053f7cb  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0053f7ce  5f                   pop edi
// 0053f7cf  5e                   pop esi
// 0053f7d0  8d04aa               lea eax, [edx + ebp*4]
// 0053f7d3  5d                   pop ebp
// 0053f7d4  5b                   pop ebx
// 0053f7d5  c3                   ret 
// standard library deque<ptr> (function ??D?$_Deque_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@$00@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
