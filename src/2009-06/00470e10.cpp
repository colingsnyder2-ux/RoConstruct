// from server: 100% by auto
// roc 2009-06 00470e10  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00470e10
//
// 00470e10  64a100000000         mov eax, dword ptr fs:[0]
// 00470e16  6aff                 push -1
// 00470e18  6868a88600           push 0x86a868
// 00470e1d  50                   push eax
// 00470e1e  64892500000000       mov dword ptr fs:[0], esp
// 00470e25  83ec28               sub esp, 0x28
// 00470e28  53                   push ebx
// 00470e29  55                   push ebp
// 00470e2a  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 00470e2e  56                   push esi
// 00470e2f  55                   push ebp
// 00470e30  8bf1                 mov esi, ecx
// 00470e32  e879c11500           call 0x5ccfb0
// 00470e37  8bd8                 mov ebx, eax
// 00470e39  85f6                 test esi, esi
// 00470e3b  7506                 jne 0x470e43
// 00470e3d  ff15ace98900         call dword ptr [0x89e9ac]
// 00470e43  8b4618               mov eax, dword ptr [esi + 0x18]
// 00470e46  57                   push edi
// 00470e47  8b3e                 mov edi, dword ptr [esi]
// 00470e49  89442414             mov dword ptr [esp + 0x14], eax
// 00470e4d  85ff                 test edi, edi
// 00470e4f  7404                 je 0x470e55
// 00470e51  3bff                 cmp edi, edi
// 00470e53  7406                 je 0x470e5b
// 00470e55  ff15ace98900         call dword ptr [0x89e9ac]
// 00470e5b  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 00470e5f  7412                 je 0x470e73
// 00470e61  8d4b0c               lea ecx, [ebx + 0xc]
// 00470e64  51                   push ecx
// 00470e65  55                   push ebp
// 00470e66  ff15e0e48900         call dword ptr [0x89e4e0]
// 00470e6c  83c408               add esp, 8
// 00470e6f  84c0                 test al, al
// 00470e71  743f                 je 0x470eb2
// 00470e73  55                   push ebp
// 00470e74  8d4c241c             lea ecx, [esp + 0x1c]
// 00470e78  ff15b8e48900         call dword ptr [0x89e4b8]
// 00470e7e  33c0                 xor eax, eax
// 00470e80  89442434             mov dword ptr [esp + 0x34], eax
// 00470e84  8d542418             lea edx, [esp + 0x18]
// 00470e88  52                   push edx
// 00470e89  53                   push ebx
// 00470e8a  89442448             mov dword ptr [esp + 0x48], eax
// 00470e8e  57                   push edi
// 00470e8f  8d44241c             lea eax, [esp + 0x1c]
// 00470e93  50                   push eax
// 00470e94  8bce                 mov ecx, esi
// 00470e96  e885fcffff           call 0x470b20
// 00470e9b  8b38                 mov edi, dword ptr [eax]
// 00470e9d  8b5804               mov ebx, dword ptr [eax + 4]
// 00470ea0  8d4c2418             lea ecx, [esp + 0x18]
// 00470ea4  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 00470eac  ff15c4e48900         call dword ptr [0x89e4c4]
// 00470eb2  85ff                 test edi, edi
// 00470eb4  7529                 jne 0x470edf
// 00470eb6  ff15ace98900         call dword ptr [0x89e9ac]
// 00470ebc  3b5f18               cmp ebx, dword ptr [edi + 0x18]
// 00470ebf  5f                   pop edi
// 00470ec0  7506                 jne 0x470ec8
// 00470ec2  ff15ace98900         call dword ptr [0x89e9ac]
// 00470ec8  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00470ecc  5e                   pop esi
// 00470ecd  5d                   pop ebp
// 00470ece  8d4328               lea eax, [ebx + 0x28]
// 00470ed1  5b                   pop ebx
// 00470ed2  64890d00000000       mov dword ptr fs:[0], ecx
// 00470ed9  83c434               add esp, 0x34
// 00470edc  c20400               ret 4
// 00470edf  8b3f                 mov edi, dword ptr [edi]
// 00470ee1  ebd9                 jmp 0x470ebc
// standard library map_str<ptr> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@@std@@QAEAAPAUT@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
