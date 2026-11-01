// from server: 100% by auto
// roc 2009-12 007c6770  unit: RBX::ScoreHud  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c6770
//
// 007c6770  83ec08               sub esp, 8
// 007c6773  53                   push ebx
// 007c6774  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 007c6778  56                   push esi
// 007c6779  8bf1                 mov esi, ecx
// 007c677b  8b4610               mov eax, dword ptr [esi + 0x10]
// 007c677e  57                   push edi
// 007c677f  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 007c6782  8bc8                 mov ecx, eax
// 007c6784  2bcf                 sub ecx, edi
// 007c6786  c1f903               sar ecx, 3
// 007c6789  3bcb                 cmp ecx, ebx
// 007c678b  7705                 ja 0x7c6792
// 007c678d  e86efcffff           call 0x7c6400
// 007c6792  3bf8                 cmp edi, eax
// 007c6794  7606                 jbe 0x7c679c
// 007c6796  ff1560b79800         call dword ptr [0x98b760]
// 007c679c  8b36                 mov esi, dword ptr [esi]
// 007c679e  55                   push ebp
// 007c679f  8bee                 mov ebp, esi
// 007c67a1  897c2414             mov dword ptr [esp + 0x14], edi
// 007c67a5  85f6                 test esi, esi
// 007c67a7  7518                 jne 0x7c67c1
// 007c67a9  ff1560b79800         call dword ptr [0x98b760]
// 007c67af  33c0                 xor eax, eax
// 007c67b1  8d3cdf               lea edi, [edi + ebx*8]
// 007c67b4  3b7810               cmp edi, dword ptr [eax + 0x10]
// 007c67b7  7713                 ja 0x7c67cc
// 007c67b9  85f6                 test esi, esi
// 007c67bb  7408                 je 0x7c67c5
// 007c67bd  8b36                 mov esi, dword ptr [esi]
// 007c67bf  eb06                 jmp 0x7c67c7
// 007c67c1  8b06                 mov eax, dword ptr [esi]
// 007c67c3  ebec                 jmp 0x7c67b1
// 007c67c5  33f6                 xor esi, esi
// 007c67c7  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 007c67ca  730a                 jae 0x7c67d6
// 007c67cc  8b3560b79800         mov esi, dword ptr [0x98b760]
// 007c67d2  ffd6                 call esi
// 007c67d4  eb06                 jmp 0x7c67dc
// 007c67d6  8b3560b79800         mov esi, dword ptr [0x98b760]
// 007c67dc  85ed                 test ebp, ebp
// 007c67de  7517                 jne 0x7c67f7
// 007c67e0  ffd6                 call esi
// 007c67e2  33c0                 xor eax, eax
// 007c67e4  5d                   pop ebp
// 007c67e5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 007c67e8  7202                 jb 0x7c67ec
// 007c67ea  ffd6                 call esi
// 007c67ec  8bc7                 mov eax, edi
// 007c67ee  5f                   pop edi
// 007c67ef  5e                   pop esi
// 007c67f0  5b                   pop ebx
// 007c67f1  83c408               add esp, 8
// 007c67f4  c20400               ret 4
// 007c67f7  8b4500               mov eax, dword ptr [ebp]
// 007c67fa  ebe8                 jmp 0x7c67e4
// standard library vector<double> (function ?at@?$vector@NV?$allocator@N@std@@@std@@QBEABNI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
