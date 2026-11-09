// from server: 100% by auto
// roc 2008-06 00651250  unit: RBX::ScoreHud  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00651250
//
// 00651250  83ec08               sub esp, 8
// 00651253  53                   push ebx
// 00651254  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00651258  56                   push esi
// 00651259  8bf1                 mov esi, ecx
// 0065125b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0065125e  57                   push edi
// 0065125f  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00651262  8bc8                 mov ecx, eax
// 00651264  2bcf                 sub ecx, edi
// 00651266  c1f903               sar ecx, 3
// 00651269  3bcb                 cmp ecx, ebx
// 0065126b  7705                 ja 0x651272
// 0065126d  e84ecde1ff           call 0x46dfc0
// 00651272  3bf8                 cmp edi, eax
// 00651274  7606                 jbe 0x65127c
// 00651276  ff1590288000         call dword ptr [0x802890]
// 0065127c  8b36                 mov esi, dword ptr [esi]
// 0065127e  55                   push ebp
// 0065127f  8bee                 mov ebp, esi
// 00651281  897c2414             mov dword ptr [esp + 0x14], edi
// 00651285  85f6                 test esi, esi
// 00651287  7518                 jne 0x6512a1
// 00651289  ff1590288000         call dword ptr [0x802890]
// 0065128f  33c0                 xor eax, eax
// 00651291  8d3cdf               lea edi, [edi + ebx*8]
// 00651294  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00651297  7713                 ja 0x6512ac
// 00651299  85f6                 test esi, esi
// 0065129b  7408                 je 0x6512a5
// 0065129d  8b36                 mov esi, dword ptr [esi]
// 0065129f  eb06                 jmp 0x6512a7
// 006512a1  8b06                 mov eax, dword ptr [esi]
// 006512a3  ebec                 jmp 0x651291
// 006512a5  33f6                 xor esi, esi
// 006512a7  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 006512aa  730a                 jae 0x6512b6
// 006512ac  8b3590288000         mov esi, dword ptr [0x802890]
// 006512b2  ffd6                 call esi
// 006512b4  eb06                 jmp 0x6512bc
// 006512b6  8b3590288000         mov esi, dword ptr [0x802890]
// 006512bc  85ed                 test ebp, ebp
// 006512be  7517                 jne 0x6512d7
// 006512c0  ffd6                 call esi
// 006512c2  33c0                 xor eax, eax
// 006512c4  5d                   pop ebp
// 006512c5  3b7810               cmp edi, dword ptr [eax + 0x10]
// 006512c8  7202                 jb 0x6512cc
// 006512ca  ffd6                 call esi
// 006512cc  8bc7                 mov eax, edi
// 006512ce  5f                   pop edi
// 006512cf  5e                   pop esi
// 006512d0  5b                   pop ebx
// 006512d1  83c408               add esp, 8
// 006512d4  c20400               ret 4
// 006512d7  8b4500               mov eax, dword ptr [ebp]
// 006512da  ebe8                 jmp 0x6512c4
// standard library vector<double> (function ?at@?$vector@NV?$allocator@N@std@@@std@@QBEABNI@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
