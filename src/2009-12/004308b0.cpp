// from server: 100% by auto
// roc 2009-12 004308b0  unit: COutputView  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004308b0
//
// 004308b0  53                   push ebx
// 004308b1  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 004308b7  55                   push ebp
// 004308b8  56                   push esi
// 004308b9  8bf1                 mov esi, ecx
// 004308bb  8b4604               mov eax, dword ptr [esi + 4]
// 004308be  57                   push edi
// 004308bf  8bf8                 mov edi, eax
// 004308c1  83e003               and eax, 3
// 004308c4  8be8                 mov ebp, eax
// 004308c6  8b06                 mov eax, dword ptr [esi]
// 004308c8  c1ef02               shr edi, 2
// 004308cb  85c0                 test eax, eax
// 004308cd  7508                 jne 0x4308d7
// 004308cf  ffd3                 call ebx
// 004308d1  8b06                 mov eax, dword ptr [esi]
// 004308d3  85c0                 test eax, eax
// 004308d5  7404                 je 0x4308db
// 004308d7  8b08                 mov ecx, dword ptr [eax]
// 004308d9  eb02                 jmp 0x4308dd
// 004308db  33c9                 xor ecx, ecx
// 004308dd  85c0                 test eax, eax
// 004308df  7404                 je 0x4308e5
// 004308e1  8b00                 mov eax, dword ptr [eax]
// 004308e3  eb02                 jmp 0x4308e7
// 004308e5  33c0                 xor eax, eax
// 004308e7  8b401c               mov eax, dword ptr [eax + 0x1c]
// 004308ea  034118               add eax, dword ptr [ecx + 0x18]
// 004308ed  394604               cmp dword ptr [esi + 4], eax
// 004308f0  7202                 jb 0x4308f4
// 004308f2  ffd3                 call ebx
// 004308f4  8b36                 mov esi, dword ptr [esi]
// 004308f6  85f6                 test esi, esi
// 004308f8  7404                 je 0x4308fe
// 004308fa  8b06                 mov eax, dword ptr [esi]
// 004308fc  eb02                 jmp 0x430900
// 004308fe  33c0                 xor eax, eax
// 00430900  397814               cmp dword ptr [eax + 0x14], edi
// 00430903  770d                 ja 0x430912
// 00430905  85f6                 test esi, esi
// 00430907  7404                 je 0x43090d
// 00430909  8b06                 mov eax, dword ptr [esi]
// 0043090b  eb02                 jmp 0x43090f
// 0043090d  33c0                 xor eax, eax
// 0043090f  2b7814               sub edi, dword ptr [eax + 0x14]
// 00430912  85f6                 test esi, esi
// 00430914  7410                 je 0x430926
// 00430916  8b36                 mov esi, dword ptr [esi]
// 00430918  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0043091b  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0043091e  5f                   pop edi
// 0043091f  5e                   pop esi
// 00430920  8d04aa               lea eax, [edx + ebp*4]
// 00430923  5d                   pop ebp
// 00430924  5b                   pop ebx
// 00430925  c3                   ret 
// 00430926  33f6                 xor esi, esi
// 00430928  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0043092b  8b14b9               mov edx, dword ptr [ecx + edi*4]
// 0043092e  5f                   pop edi
// 0043092f  5e                   pop esi
// 00430930  8d04aa               lea eax, [edx + ebp*4]
// 00430933  5d                   pop ebp
// 00430934  5b                   pop ebx
// 00430935  c3                   ret 
// standard library deque<ptr> (function ??D?$_Deque_const_iterator@PAUT@@V?$allocator@PAUT@@@std@@$00@std@@QBEABQAUT@@XZ)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
