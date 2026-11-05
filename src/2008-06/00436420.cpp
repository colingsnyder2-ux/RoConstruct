// from server: 100% by auto
// roc 2008-06 00436420  unit: COutputView  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00436420
//
// 00436420  53                   push ebx
// 00436421  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00436427  55                   push ebp
// 00436428  56                   push esi
// 00436429  8bf1                 mov esi, ecx
// 0043642b  8b4604               mov eax, dword ptr [esi + 4]
// 0043642e  57                   push edi
// 0043642f  8bf8                 mov edi, eax
// 00436431  83e003               and eax, 3
// 00436434  8be8                 mov ebp, eax
// 00436436  8b06                 mov eax, dword ptr [esi]
// 00436438  c1ef02               shr edi, 2
// 0043643b  85c0                 test eax, eax
// 0043643d  7508                 jne 0x436447
// 0043643f  ffd3                 call ebx
// 00436441  8b06                 mov eax, dword ptr [esi]
// 00436443  85c0                 test eax, eax
// 00436445  7404                 je 0x43644b
// 00436447  8b08                 mov ecx, dword ptr [eax]
// 00436449  eb02                 jmp 0x43644d
// 0043644b  33c9                 xor ecx, ecx
// 0043644d  85c0                 test eax, eax
// 0043644f  7404                 je 0x436455
// 00436451  8b00                 mov eax, dword ptr [eax]
// 00436453  eb02                 jmp 0x436457
// 00436455  33c0                 xor eax, eax
// 00436457  8b401c               mov eax, dword ptr [eax + 0x1c]
// 0043645a  034118               add eax, dword ptr [ecx + 0x18]
// 0043645d  394604               cmp dword ptr [esi + 4], eax
// 00436460  7202                 jb 0x436464
// 00436462  ffd3                 call ebx
// 00436464  8b36                 mov esi, dword ptr [esi]
// 00436466  85f6                 test esi, esi
// 00436468  7404                 je 0x43646e
// 0043646a  8b06                 mov eax, dword ptr [esi]
// 0043646c  eb02                 jmp 0x436470
// 0043646e  33c0                 xor eax, eax
// 00436470  397814               cmp dword ptr [eax + 0x14], edi
// 00436473  770d                 ja 0x436482
// 00436475  85f6                 test esi, esi
// 00436477  7404                 je 0x43647d
// 00436479  8b06                 mov eax, dword ptr [esi]
// 0043647b  eb02                 jmp 0x43647f
// 0043647d  33c0                 xor eax, eax
// 0043647f  2b7814               sub edi, dword ptr [eax + 0x14]
// 00436482  85f6                 test esi, esi
// 00436484  7410                 je 0x436496
// 00436486  8b36                 mov esi, dword ptr [esi]
// 00436488  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0043648b  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0043648e  5f                   pop edi
// 0043648f  5e                   pop esi
// 00436490  8d04aa               lea eax, [edx + ebp*4]
// 00436493  5d                   pop ebp
// 00436494  5b                   pop ebx
// 00436495  c3                   ret 
// 00436496  33f6                 xor esi, esi
// 00436498  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0043649b  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0043649e  5f                   pop edi
// 0043649f  5e                   pop esi
// 004364a0  8d04aa               lea eax, [edx + ebp*4]
// 004364a3  5d                   pop ebp
// 004364a4  5b                   pop ebx
// 004364a5  c3                   ret 
// standard library deque<ptr> (function ??D?$_Deque_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@$00@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
