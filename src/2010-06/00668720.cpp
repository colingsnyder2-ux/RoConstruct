// from server: 100% by auto
// roc 2010-06 00668720  unit: RBX::VSpawnerService::?$FactoryProduct  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00668720
//
// 00668720  83ec0c               sub esp, 0xc
// 00668723  8b442410             mov eax, dword ptr [esp + 0x10]
// 00668727  53                   push ebx
// 00668728  55                   push ebp
// 00668729  8bd9                 mov ebx, ecx
// 0066872b  8b08                 mov ecx, dword ptr [eax]
// 0066872d  8b6b14               mov ebp, dword ptr [ebx + 0x14]
// 00668730  56                   push esi
// 00668731  8b33                 mov esi, dword ptr [ebx]
// 00668733  57                   push edi
// 00668734  8b7d00               mov edi, dword ptr [ebp]
// 00668737  894c2410             mov dword ptr [esp + 0x10], ecx
// 0066873b  89742420             mov dword ptr [esp + 0x20], esi
// 0066873f  90                   nop 
// 00668740  85f6                 test esi, esi
// 00668742  7406                 je 0x66874a
// 00668744  3b742420             cmp esi, dword ptr [esp + 0x20]
// 00668748  7406                 je 0x668750
// 0066874a  ff150ca99e00         call dword ptr [0x9ea90c]
// 00668750  3bfd                 cmp edi, ebp
// 00668752  7458                 je 0x6687ac
// 00668754  85f6                 test esi, esi
// 00668756  7531                 jne 0x668789
// 00668758  ff150ca99e00         call dword ptr [0x9ea90c]
// 0066875e  33c0                 xor eax, eax
// 00668760  3b7814               cmp edi, dword ptr [eax + 0x14]
// 00668763  7506                 jne 0x66876b
// 00668765  ff150ca99e00         call dword ptr [0x9ea90c]
// 0066876b  8b542410             mov edx, dword ptr [esp + 0x10]
// 0066876f  395708               cmp dword ptr [edi + 8], edx
// 00668772  7519                 jne 0x66878d
// 00668774  57                   push edi
// 00668775  56                   push esi
// 00668776  8d44241c             lea eax, [esp + 0x1c]
// 0066877a  50                   push eax
// 0066877b  8bcb                 mov ecx, ebx
// 0066877d  e8be602900           call 0x8fe840
// 00668782  8b30                 mov esi, dword ptr [eax]
// 00668784  8b7804               mov edi, dword ptr [eax + 4]
// 00668787  ebb7                 jmp 0x668740
// 00668789  8b06                 mov eax, dword ptr [esi]
// 0066878b  ebd3                 jmp 0x668760
// 0066878d  85f6                 test esi, esi
// 0066878f  7517                 jne 0x6687a8
// 00668791  ff150ca99e00         call dword ptr [0x9ea90c]
// 00668797  33c0                 xor eax, eax
// 00668799  3b7814               cmp edi, dword ptr [eax + 0x14]
// 0066879c  7506                 jne 0x6687a4
// 0066879e  ff150ca99e00         call dword ptr [0x9ea90c]
// 006687a4  8b3f                 mov edi, dword ptr [edi]
// 006687a6  eb98                 jmp 0x668740
// 006687a8  8b06                 mov eax, dword ptr [esi]
// 006687aa  ebed                 jmp 0x668799
// 006687ac  5f                   pop edi
// 006687ad  5e                   pop esi
// 006687ae  5d                   pop ebp
// 006687af  5b                   pop ebx
// 006687b0  83c40c               add esp, 0xc
// 006687b3  c20400               ret 4
// standard library list<ptr> (function ?remove@?$list@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: list<ptr>
struct T; typedef T* E;
#include <list>
template class std::list<E>;
