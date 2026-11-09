// from server: 100% by auto
// roc 2008-06 0046f5a0  unit: RBX::LDraw2Lua::LDrawParser  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046f5a0
//
// 0046f5a0  83ec08               sub esp, 8
// 0046f5a3  53                   push ebx
// 0046f5a4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0046f5a8  56                   push esi
// 0046f5a9  8bf1                 mov esi, ecx
// 0046f5ab  8b4610               mov eax, dword ptr [esi + 0x10]
// 0046f5ae  57                   push edi
// 0046f5af  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0046f5b2  8bc8                 mov ecx, eax
// 0046f5b4  2bcf                 sub ecx, edi
// 0046f5b6  c1f902               sar ecx, 2
// 0046f5b9  3bcb                 cmp ecx, ebx
// 0046f5bb  7705                 ja 0x46f5c2
// 0046f5bd  e8fee9ffff           call 0x46dfc0
// 0046f5c2  3bf8                 cmp edi, eax
// 0046f5c4  7606                 jbe 0x46f5cc
// 0046f5c6  ff1590288000         call dword ptr [0x802890]
// 0046f5cc  8b36                 mov esi, dword ptr [esi]
// 0046f5ce  55                   push ebp
// 0046f5cf  8bee                 mov ebp, esi
// 0046f5d1  897c2414             mov dword ptr [esp + 0x14], edi
// 0046f5d5  85f6                 test esi, esi
// 0046f5d7  7518                 jne 0x46f5f1
// 0046f5d9  ff1590288000         call dword ptr [0x802890]
// 0046f5df  33c0                 xor eax, eax
// 0046f5e1  8d3c9f               lea edi, [edi + ebx*4]
// 0046f5e4  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0046f5e7  7713                 ja 0x46f5fc
// 0046f5e9  85f6                 test esi, esi
// 0046f5eb  7408                 je 0x46f5f5
// 0046f5ed  8b36                 mov esi, dword ptr [esi]
// 0046f5ef  eb06                 jmp 0x46f5f7
// 0046f5f1  8b06                 mov eax, dword ptr [esi]
// 0046f5f3  ebec                 jmp 0x46f5e1
// 0046f5f5  33f6                 xor esi, esi
// 0046f5f7  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0046f5fa  730a                 jae 0x46f606
// 0046f5fc  8b3590288000         mov esi, dword ptr [0x802890]
// 0046f602  ffd6                 call esi
// 0046f604  eb06                 jmp 0x46f60c
// 0046f606  8b3590288000         mov esi, dword ptr [0x802890]
// 0046f60c  85ed                 test ebp, ebp
// 0046f60e  7517                 jne 0x46f627
// 0046f610  ffd6                 call esi
// 0046f612  33c0                 xor eax, eax
// 0046f614  5d                   pop ebp
// 0046f615  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0046f618  7202                 jb 0x46f61c
// 0046f61a  ffd6                 call esi
// 0046f61c  8bc7                 mov eax, edi
// 0046f61e  5f                   pop edi
// 0046f61f  5e                   pop esi
// 0046f620  5b                   pop ebx
// 0046f621  83c408               add esp, 8
// 0046f624  c20400               ret 4
// 0046f627  8b4500               mov eax, dword ptr [ebp]
// 0046f62a  ebe8                 jmp 0x46f614
// standard library vector<ptr> (function ?at@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
