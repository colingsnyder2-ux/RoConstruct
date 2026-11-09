// from server: 100% by auto
// roc 2010-06 004820b0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004820b0
//
// 004820b0  83ec08               sub esp, 8
// 004820b3  53                   push ebx
// 004820b4  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 004820b8  56                   push esi
// 004820b9  8bf1                 mov esi, ecx
// 004820bb  8b4610               mov eax, dword ptr [esi + 0x10]
// 004820be  57                   push edi
// 004820bf  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004820c2  8bc8                 mov ecx, eax
// 004820c4  2bcf                 sub ecx, edi
// 004820c6  c1f906               sar ecx, 6
// 004820c9  3bcb                 cmp ecx, ebx
// 004820cb  7705                 ja 0x4820d2
// 004820cd  e81efdffff           call 0x481df0
// 004820d2  3bf8                 cmp edi, eax
// 004820d4  7606                 jbe 0x4820dc
// 004820d6  ff150ca99e00         call dword ptr [0x9ea90c]
// 004820dc  8b36                 mov esi, dword ptr [esi]
// 004820de  55                   push ebp
// 004820df  8bee                 mov ebp, esi
// 004820e1  897c2414             mov dword ptr [esp + 0x14], edi
// 004820e5  85f6                 test esi, esi
// 004820e7  751a                 jne 0x482103
// 004820e9  ff150ca99e00         call dword ptr [0x9ea90c]
// 004820ef  33c0                 xor eax, eax
// 004820f1  c1e306               shl ebx, 6
// 004820f4  03fb                 add edi, ebx
// 004820f6  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004820f9  7713                 ja 0x48210e
// 004820fb  85f6                 test esi, esi
// 004820fd  7408                 je 0x482107
// 004820ff  8b36                 mov esi, dword ptr [esi]
// 00482101  eb06                 jmp 0x482109
// 00482103  8b06                 mov eax, dword ptr [esi]
// 00482105  ebea                 jmp 0x4820f1
// 00482107  33f6                 xor esi, esi
// 00482109  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0048210c  730a                 jae 0x482118
// 0048210e  8b350ca99e00         mov esi, dword ptr [0x9ea90c]
// 00482114  ffd6                 call esi
// 00482116  eb06                 jmp 0x48211e
// 00482118  8b350ca99e00         mov esi, dword ptr [0x9ea90c]
// 0048211e  85ed                 test ebp, ebp
// 00482120  7517                 jne 0x482139
// 00482122  ffd6                 call esi
// 00482124  33c0                 xor eax, eax
// 00482126  5d                   pop ebp
// 00482127  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0048212a  7202                 jb 0x48212e
// 0048212c  ffd6                 call esi
// 0048212e  8bc7                 mov eax, edi
// 00482130  5f                   pop edi
// 00482131  5e                   pop esi
// 00482132  5b                   pop ebx
// 00482133  83c408               add esp, 8
// 00482136  c20400               ret 4
// 00482139  8b4500               mov eax, dword ptr [ebp]
// 0048213c  ebe8                 jmp 0x482126
// standard library vector<pod64> (function ?at@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QBEABUE@@I@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
