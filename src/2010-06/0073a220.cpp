// from server: 100% by auto
// roc 2010-06 0073a220  unit: seg_00730000  size: 211 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0073a220
//
// 0073a220  64a100000000         mov eax, dword ptr fs:[0]
// 0073a226  6aff                 push -1
// 0073a228  68f88a9900           push 0x998af8
// 0073a22d  50                   push eax
// 0073a22e  64892500000000       mov dword ptr fs:[0], esp
// 0073a235  83ec28               sub esp, 0x28
// 0073a238  53                   push ebx
// 0073a239  55                   push ebp
// 0073a23a  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 0073a23e  56                   push esi
// 0073a23f  55                   push ebp
// 0073a240  8bf1                 mov esi, ecx
// 0073a242  e8699ce5ff           call 0x593eb0
// 0073a247  8bd8                 mov ebx, eax
// 0073a249  85f6                 test esi, esi
// 0073a24b  7506                 jne 0x73a253
// 0073a24d  ff150ca99e00         call dword ptr [0x9ea90c]
// 0073a253  8b4618               mov eax, dword ptr [esi + 0x18]
// 0073a256  57                   push edi
// 0073a257  8b3e                 mov edi, dword ptr [esi]
// 0073a259  89442414             mov dword ptr [esp + 0x14], eax
// 0073a25d  85ff                 test edi, edi
// 0073a25f  7404                 je 0x73a265
// 0073a261  3bff                 cmp edi, edi
// 0073a263  7406                 je 0x73a26b
// 0073a265  ff150ca99e00         call dword ptr [0x9ea90c]
// 0073a26b  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 0073a26f  7412                 je 0x73a283
// 0073a271  8d4b0c               lea ecx, [ebx + 0xc]
// 0073a274  51                   push ecx
// 0073a275  55                   push ebp
// 0073a276  ff151ca59e00         call dword ptr [0x9ea51c]
// 0073a27c  83c408               add esp, 8
// 0073a27f  84c0                 test al, al
// 0073a281  743f                 je 0x73a2c2
// 0073a283  55                   push ebp
// 0073a284  8d4c241c             lea ecx, [esp + 0x1c]
// 0073a288  ff150ca49e00         call dword ptr [0x9ea40c]
// 0073a28e  33c0                 xor eax, eax
// 0073a290  89442434             mov dword ptr [esp + 0x34], eax
// 0073a294  8d542418             lea edx, [esp + 0x18]
// 0073a298  52                   push edx
// 0073a299  53                   push ebx
// 0073a29a  89442448             mov dword ptr [esp + 0x48], eax
// 0073a29e  57                   push edi
// 0073a29f  8d44241c             lea eax, [esp + 0x1c]
// 0073a2a3  50                   push eax
// 0073a2a4  8bce                 mov ecx, esi
// 0073a2a6  e8d5f9ffff           call 0x739c80
// 0073a2ab  8b38                 mov edi, dword ptr [eax]
// 0073a2ad  8b5804               mov ebx, dword ptr [eax + 4]
// 0073a2b0  8d4c2418             lea ecx, [esp + 0x18]
// 0073a2b4  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 0073a2bc  ff1500a49e00         call dword ptr [0x9ea400]
// 0073a2c2  85ff                 test edi, edi
// 0073a2c4  7529                 jne 0x73a2ef
// 0073a2c6  ff150ca99e00         call dword ptr [0x9ea90c]
// 0073a2cc  3b5f18               cmp ebx, dword ptr [edi + 0x18]
// 0073a2cf  5f                   pop edi
// 0073a2d0  7506                 jne 0x73a2d8
// 0073a2d2  ff150ca99e00         call dword ptr [0x9ea90c]
// 0073a2d8  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0073a2dc  5e                   pop esi
// 0073a2dd  5d                   pop ebp
// 0073a2de  8d4328               lea eax, [ebx + 0x28]
// 0073a2e1  5b                   pop ebx
// 0073a2e2  64890d00000000       mov dword ptr fs:[0], ecx
// 0073a2e9  83c434               add esp, 0x34
// 0073a2ec  c20400               ret 4
// 0073a2ef  8b3f                 mov edi, dword ptr [edi]
// 0073a2f1  ebd9                 jmp 0x73a2cc
// standard library map_str<ptr> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@@std@@QAEAAPAUT@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
