// from server: 100% by auto
// roc 2010-06 005d0c70  unit: RBX::VInstance::?$NonFactoryProduct  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005d0c70
//
// 005d0c70  64a100000000         mov eax, dword ptr fs:[0]
// 005d0c76  6aff                 push -1
// 005d0c78  68f88a9900           push 0x998af8
// 005d0c7d  50                   push eax
// 005d0c7e  64892500000000       mov dword ptr fs:[0], esp
// 005d0c85  83ec28               sub esp, 0x28
// 005d0c88  53                   push ebx
// 005d0c89  55                   push ebp
// 005d0c8a  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 005d0c8e  56                   push esi
// 005d0c8f  55                   push ebp
// 005d0c90  8bf1                 mov esi, ecx
// 005d0c92  e81932fcff           call 0x593eb0
// 005d0c97  8bd8                 mov ebx, eax
// 005d0c99  85f6                 test esi, esi
// 005d0c9b  7506                 jne 0x5d0ca3
// 005d0c9d  ff150ca99e00         call dword ptr [0x9ea90c]
// 005d0ca3  8b4618               mov eax, dword ptr [esi + 0x18]
// 005d0ca6  57                   push edi
// 005d0ca7  8b3e                 mov edi, dword ptr [esi]
// 005d0ca9  89442414             mov dword ptr [esp + 0x14], eax
// 005d0cad  85ff                 test edi, edi
// 005d0caf  7404                 je 0x5d0cb5
// 005d0cb1  3bff                 cmp edi, edi
// 005d0cb3  7406                 je 0x5d0cbb
// 005d0cb5  ff150ca99e00         call dword ptr [0x9ea90c]
// 005d0cbb  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 005d0cbf  7412                 je 0x5d0cd3
// 005d0cc1  8d4b0c               lea ecx, [ebx + 0xc]
// 005d0cc4  51                   push ecx
// 005d0cc5  55                   push ebp
// 005d0cc6  ff151ca59e00         call dword ptr [0x9ea51c]
// 005d0ccc  83c408               add esp, 8
// 005d0ccf  84c0                 test al, al
// 005d0cd1  743f                 je 0x5d0d12
// 005d0cd3  55                   push ebp
// 005d0cd4  8d4c241c             lea ecx, [esp + 0x1c]
// 005d0cd8  ff150ca49e00         call dword ptr [0x9ea40c]
// 005d0cde  33c0                 xor eax, eax
// 005d0ce0  89442434             mov dword ptr [esp + 0x34], eax
// 005d0ce4  8d542418             lea edx, [esp + 0x18]
// 005d0ce8  52                   push edx
// 005d0ce9  53                   push ebx
// 005d0cea  89442448             mov dword ptr [esp + 0x48], eax
// 005d0cee  57                   push edi
// 005d0cef  8d44241c             lea eax, [esp + 0x1c]
// 005d0cf3  50                   push eax
// 005d0cf4  8bce                 mov ecx, esi
// 005d0cf6  e8e5f3ffff           call 0x5d00e0
// 005d0cfb  8b38                 mov edi, dword ptr [eax]
// 005d0cfd  8b5804               mov ebx, dword ptr [eax + 4]
// 005d0d00  8d4c2418             lea ecx, [esp + 0x18]
// 005d0d04  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 005d0d0c  ff1500a49e00         call dword ptr [0x9ea400]
// 005d0d12  85ff                 test edi, edi
// 005d0d14  7529                 jne 0x5d0d3f
// 005d0d16  ff150ca99e00         call dword ptr [0x9ea90c]
// 005d0d1c  3b5f18               cmp ebx, dword ptr [edi + 0x18]
// 005d0d1f  5f                   pop edi
// 005d0d20  7506                 jne 0x5d0d28
// 005d0d22  ff150ca99e00         call dword ptr [0x9ea90c]
// 005d0d28  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 005d0d2c  5e                   pop esi
// 005d0d2d  5d                   pop ebp
// 005d0d2e  8d4328               lea eax, [ebx + 0x28]
// 005d0d31  5b                   pop ebx
// 005d0d32  64890d00000000       mov dword ptr fs:[0], ecx
// 005d0d39  83c434               add esp, 0x34
// 005d0d3c  c20400               ret 4
// 005d0d3f  8b3f                 mov edi, dword ptr [edi]
// 005d0d41  ebd9                 jmp 0x5d0d1c
// standard library map_str<ptr> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@@std@@QAEAAPAUT@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
