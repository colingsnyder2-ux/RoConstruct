// from server: 100% by auto
// roc 2010-06 00483420  unit: RBX::LDraw2Lua::LDrawParser  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00483420
//
// 00483420  83ec08               sub esp, 8
// 00483423  53                   push ebx
// 00483424  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00483428  56                   push esi
// 00483429  8bf1                 mov esi, ecx
// 0048342b  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048342e  57                   push edi
// 0048342f  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00483432  8bc8                 mov ecx, eax
// 00483434  2bcf                 sub ecx, edi
// 00483436  c1f902               sar ecx, 2
// 00483439  3bcb                 cmp ecx, ebx
// 0048343b  7705                 ja 0x483442
// 0048343d  e8aee9ffff           call 0x481df0
// 00483442  3bf8                 cmp edi, eax
// 00483444  7606                 jbe 0x48344c
// 00483446  ff150ca99e00         call dword ptr [0x9ea90c]
// 0048344c  8b36                 mov esi, dword ptr [esi]
// 0048344e  55                   push ebp
// 0048344f  8bee                 mov ebp, esi
// 00483451  897c2414             mov dword ptr [esp + 0x14], edi
// 00483455  85f6                 test esi, esi
// 00483457  7518                 jne 0x483471
// 00483459  ff150ca99e00         call dword ptr [0x9ea90c]
// 0048345f  33c0                 xor eax, eax
// 00483461  8d3c9f               lea edi, [edi + ebx*4]
// 00483464  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00483467  7713                 ja 0x48347c
// 00483469  85f6                 test esi, esi
// 0048346b  7408                 je 0x483475
// 0048346d  8b36                 mov esi, dword ptr [esi]
// 0048346f  eb06                 jmp 0x483477
// 00483471  8b06                 mov eax, dword ptr [esi]
// 00483473  ebec                 jmp 0x483461
// 00483475  33f6                 xor esi, esi
// 00483477  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0048347a  730a                 jae 0x483486
// 0048347c  8b350ca99e00         mov esi, dword ptr [0x9ea90c]
// 00483482  ffd6                 call esi
// 00483484  eb06                 jmp 0x48348c
// 00483486  8b350ca99e00         mov esi, dword ptr [0x9ea90c]
// 0048348c  85ed                 test ebp, ebp
// 0048348e  7517                 jne 0x4834a7
// 00483490  ffd6                 call esi
// 00483492  33c0                 xor eax, eax
// 00483494  5d                   pop ebp
// 00483495  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00483498  7202                 jb 0x48349c
// 0048349a  ffd6                 call esi
// 0048349c  8bc7                 mov eax, edi
// 0048349e  5f                   pop edi
// 0048349f  5e                   pop esi
// 004834a0  5b                   pop ebx
// 004834a1  83c408               add esp, 8
// 004834a4  c20400               ret 4
// 004834a7  8b4500               mov eax, dword ptr [ebp]
// 004834aa  ebe8                 jmp 0x483494
// standard library vector<ptr> (function ?at@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QBEABQAUT@@I@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
