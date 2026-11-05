// from server: 100% by auto
// roc 2008-06 0046e280  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046e280
//
// 0046e280  83ec08               sub esp, 8
// 0046e283  53                   push ebx
// 0046e284  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0046e288  56                   push esi
// 0046e289  8bf1                 mov esi, ecx
// 0046e28b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0046e28e  57                   push edi
// 0046e28f  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0046e292  8bc8                 mov ecx, eax
// 0046e294  2bcf                 sub ecx, edi
// 0046e296  c1f906               sar ecx, 6
// 0046e299  3bcb                 cmp ecx, ebx
// 0046e29b  7705                 ja 0x46e2a2
// 0046e29d  e81efdffff           call 0x46dfc0
// 0046e2a2  3bf8                 cmp edi, eax
// 0046e2a4  7606                 jbe 0x46e2ac
// 0046e2a6  ff1590288000         call dword ptr [0x802890]
// 0046e2ac  8b36                 mov esi, dword ptr [esi]
// 0046e2ae  55                   push ebp
// 0046e2af  8bee                 mov ebp, esi
// 0046e2b1  897c2414             mov dword ptr [esp + 0x14], edi
// 0046e2b5  85f6                 test esi, esi
// 0046e2b7  751a                 jne 0x46e2d3
// 0046e2b9  ff1590288000         call dword ptr [0x802890]
// 0046e2bf  33c0                 xor eax, eax
// 0046e2c1  c1e306               shl ebx, 6
// 0046e2c4  03fb                 add edi, ebx
// 0046e2c6  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0046e2c9  7713                 ja 0x46e2de
// 0046e2cb  85f6                 test esi, esi
// 0046e2cd  7408                 je 0x46e2d7
// 0046e2cf  8b36                 mov esi, dword ptr [esi]
// 0046e2d1  eb06                 jmp 0x46e2d9
// 0046e2d3  8b06                 mov eax, dword ptr [esi]
// 0046e2d5  ebea                 jmp 0x46e2c1
// 0046e2d7  33f6                 xor esi, esi
// 0046e2d9  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0046e2dc  730a                 jae 0x46e2e8
// 0046e2de  8b3590288000         mov esi, dword ptr [0x802890]
// 0046e2e4  ffd6                 call esi
// 0046e2e6  eb06                 jmp 0x46e2ee
// 0046e2e8  8b3590288000         mov esi, dword ptr [0x802890]
// 0046e2ee  85ed                 test ebp, ebp
// 0046e2f0  7517                 jne 0x46e309
// 0046e2f2  ffd6                 call esi
// 0046e2f4  33c0                 xor eax, eax
// 0046e2f6  5d                   pop ebp
// 0046e2f7  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0046e2fa  7202                 jb 0x46e2fe
// 0046e2fc  ffd6                 call esi
// 0046e2fe  8bc7                 mov eax, edi
// 0046e300  5f                   pop edi
// 0046e301  5e                   pop esi
// 0046e302  5b                   pop ebx
// 0046e303  83c408               add esp, 8
// 0046e306  c20400               ret 4
// 0046e309  8b4500               mov eax, dword ptr [ebp]
// 0046e30c  ebe8                 jmp 0x46e2f6
// standard library vector<pod64> (function ?at@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
