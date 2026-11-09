// from server: 100% by auto
// roc 2009-12 00669ee0  unit: RBX::VInstance::?$NonFactoryProduct  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00669ee0
//
// 00669ee0  64a100000000         mov eax, dword ptr fs:[0]
// 00669ee6  6aff                 push -1
// 00669ee8  68a85a9400           push 0x945aa8
// 00669eed  50                   push eax
// 00669eee  64892500000000       mov dword ptr fs:[0], esp
// 00669ef5  83ec28               sub esp, 0x28
// 00669ef8  53                   push ebx
// 00669ef9  55                   push ebp
// 00669efa  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 00669efe  56                   push esi
// 00669eff  55                   push ebp
// 00669f00  8bf1                 mov esi, ecx
// 00669f02  e8b97efcff           call 0x631dc0
// 00669f07  8bd8                 mov ebx, eax
// 00669f09  85f6                 test esi, esi
// 00669f0b  7506                 jne 0x669f13
// 00669f0d  ff1560b79800         call dword ptr [0x98b760]
// 00669f13  8b4618               mov eax, dword ptr [esi + 0x18]
// 00669f16  57                   push edi
// 00669f17  8b3e                 mov edi, dword ptr [esi]
// 00669f19  89442414             mov dword ptr [esp + 0x14], eax
// 00669f1d  85ff                 test edi, edi
// 00669f1f  7404                 je 0x669f25
// 00669f21  3bff                 cmp edi, edi
// 00669f23  7406                 je 0x669f2b
// 00669f25  ff1560b79800         call dword ptr [0x98b760]
// 00669f2b  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 00669f2f  7412                 je 0x669f43
// 00669f31  8d4b0c               lea ecx, [ebx + 0xc]
// 00669f34  51                   push ecx
// 00669f35  55                   push ebp
// 00669f36  ff15d8b59800         call dword ptr [0x98b5d8]
// 00669f3c  83c408               add esp, 8
// 00669f3f  84c0                 test al, al
// 00669f41  743f                 je 0x669f82
// 00669f43  55                   push ebp
// 00669f44  8d4c241c             lea ecx, [esp + 0x1c]
// 00669f48  ff15f0b69800         call dword ptr [0x98b6f0]
// 00669f4e  33c0                 xor eax, eax
// 00669f50  89442434             mov dword ptr [esp + 0x34], eax
// 00669f54  8d542418             lea edx, [esp + 0x18]
// 00669f58  52                   push edx
// 00669f59  53                   push ebx
// 00669f5a  89442448             mov dword ptr [esp + 0x48], eax
// 00669f5e  57                   push edi
// 00669f5f  8d44241c             lea eax, [esp + 0x1c]
// 00669f63  50                   push eax
// 00669f64  8bce                 mov ecx, esi
// 00669f66  e8e5f0ffff           call 0x669050
// 00669f6b  8b38                 mov edi, dword ptr [eax]
// 00669f6d  8b5804               mov ebx, dword ptr [eax + 4]
// 00669f70  8d4c2418             lea ecx, [esp + 0x18]
// 00669f74  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 00669f7c  ff15e4b69800         call dword ptr [0x98b6e4]
// 00669f82  85ff                 test edi, edi
// 00669f84  7529                 jne 0x669faf
// 00669f86  ff1560b79800         call dword ptr [0x98b760]
// 00669f8c  3b5f18               cmp ebx, dword ptr [edi + 0x18]
// 00669f8f  5f                   pop edi
// 00669f90  7506                 jne 0x669f98
// 00669f92  ff1560b79800         call dword ptr [0x98b760]
// 00669f98  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00669f9c  5e                   pop esi
// 00669f9d  5d                   pop ebp
// 00669f9e  8d4328               lea eax, [ebx + 0x28]
// 00669fa1  5b                   pop ebx
// 00669fa2  64890d00000000       mov dword ptr fs:[0], ecx
// 00669fa9  83c434               add esp, 0x34
// 00669fac  c20400               ret 4
// 00669faf  8b3f                 mov edi, dword ptr [edi]
// 00669fb1  ebd9                 jmp 0x669f8c
// standard library map_str<ptr> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@@std@@QAEAAPAUT@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
