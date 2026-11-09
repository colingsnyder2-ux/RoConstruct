// from server: 100% by auto
// roc 2010-06 00425db0  unit: MainLogManager  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00425db0
//
// 00425db0  55                   push ebp
// 00425db1  8bec                 mov ebp, esp
// 00425db3  6aff                 push -1
// 00425db5  6828fb9700           push 0x97fb28
// 00425dba  64a100000000         mov eax, dword ptr fs:[0]
// 00425dc0  50                   push eax
// 00425dc1  64892500000000       mov dword ptr fs:[0], esp
// 00425dc8  83ec0c               sub esp, 0xc
// 00425dcb  53                   push ebx
// 00425dcc  56                   push esi
// 00425dcd  57                   push edi
// 00425dce  8965f0               mov dword ptr [ebp - 0x10], esp
// 00425dd1  8bf1                 mov esi, ecx
// 00425dd3  6a04                 push 4
// 00425dd5  8975e8               mov dword ptr [ebp - 0x18], esi
// 00425dd8  e8c31b3800           call 0x7a79a0
// 00425ddd  83c404               add esp, 4
// 00425de0  85c0                 test eax, eax
// 00425de2  7404                 je 0x425de8
// 00425de4  8930                 mov dword ptr [eax], esi
// 00425de6  eb02                 jmp 0x425dea
// 00425de8  33c0                 xor eax, eax
// 00425dea  8906                 mov dword ptr [esi], eax
// 00425dec  8b7d08               mov edi, dword ptr [ebp + 8]
// 00425def  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00425df2  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00425df5  b893244992           mov eax, 0x92492493
// 00425dfa  f7e9                 imul ecx
// 00425dfc  03d1                 add edx, ecx
// 00425dfe  c1fa04               sar edx, 4
// 00425e01  8bc2                 mov eax, edx
// 00425e03  c1e81f               shr eax, 0x1f
// 00425e06  03c2                 add eax, edx
// 00425e08  50                   push eax
// 00425e09  8bce                 mov ecx, esi
// 00425e0b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00425e12  e8e9f1ffff           call 0x425000
// 00425e17  84c0                 test al, al
// 00425e19  7447                 je 0x425e62
// 00425e1b  8b4710               mov eax, dword ptr [edi + 0x10]
// 00425e1e  c645fc01             mov byte ptr [ebp - 4], 1
// 00425e22  8945ec               mov dword ptr [ebp - 0x14], eax
// 00425e25  39470c               cmp dword ptr [edi + 0xc], eax
// 00425e28  7606                 jbe 0x425e30
// 00425e2a  ff150ca99e00         call dword ptr [0x9ea90c]
// 00425e30  8b5f0c               mov ebx, dword ptr [edi + 0xc]
// 00425e33  3b5f10               cmp ebx, dword ptr [edi + 0x10]
// 00425e36  7606                 jbe 0x425e3e
// 00425e38  ff150ca99e00         call dword ptr [0x9ea90c]
// 00425e3e  8b460c               mov eax, dword ptr [esi + 0xc]
// 00425e41  c6450800             mov byte ptr [ebp + 8], 0
// 00425e45  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00425e48  8b5508               mov edx, dword ptr [ebp + 8]
// 00425e4b  51                   push ecx
// 00425e4c  52                   push edx
// 00425e4d  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00425e50  8d4e08               lea ecx, [esi + 8]
// 00425e53  51                   push ecx
// 00425e54  50                   push eax
// 00425e55  52                   push edx
// 00425e56  53                   push ebx
// 00425e57  e8a4e9ffff           call 0x424800
// 00425e5c  83c418               add esp, 0x18
// 00425e5f  894610               mov dword ptr [esi + 0x10], eax
// 00425e62  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00425e65  5f                   pop edi
// 00425e66  8bc6                 mov eax, esi
// 00425e68  5e                   pop esi
// 00425e69  64890d00000000       mov dword ptr fs:[0], ecx
// 00425e70  5b                   pop ebx
// 00425e71  8be5                 mov esp, ebp
// 00425e73  5d                   pop ebp
// 00425e74  c20400               ret 4
// standard library vector<string> (function ??0?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
