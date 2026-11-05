// from server: 100% by auto
// roc 2009-06 00424db0  unit: MainLogManager  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00424db0
//
// 00424db0  55                   push ebp
// 00424db1  8bec                 mov ebp, esp
// 00424db3  6aff                 push -1
// 00424db5  6868eb8400           push 0x84eb68
// 00424dba  64a100000000         mov eax, dword ptr fs:[0]
// 00424dc0  50                   push eax
// 00424dc1  64892500000000       mov dword ptr fs:[0], esp
// 00424dc8  83ec0c               sub esp, 0xc
// 00424dcb  53                   push ebx
// 00424dcc  56                   push esi
// 00424dcd  57                   push edi
// 00424dce  8965f0               mov dword ptr [ebp - 0x10], esp
// 00424dd1  8bf1                 mov esi, ecx
// 00424dd3  6a04                 push 4
// 00424dd5  8975e8               mov dword ptr [ebp - 0x18], esi
// 00424dd8  e85b3c2f00           call 0x718a38
// 00424ddd  83c404               add esp, 4
// 00424de0  85c0                 test eax, eax
// 00424de2  7404                 je 0x424de8
// 00424de4  8930                 mov dword ptr [eax], esi
// 00424de6  eb02                 jmp 0x424dea
// 00424de8  33c0                 xor eax, eax
// 00424dea  8906                 mov dword ptr [esi], eax
// 00424dec  8b7d08               mov edi, dword ptr [ebp + 8]
// 00424def  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00424df2  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00424df5  b893244992           mov eax, 0x92492493
// 00424dfa  f7e9                 imul ecx
// 00424dfc  03d1                 add edx, ecx
// 00424dfe  c1fa04               sar edx, 4
// 00424e01  8bc2                 mov eax, edx
// 00424e03  c1e81f               shr eax, 0x1f
// 00424e06  03c2                 add eax, edx
// 00424e08  50                   push eax
// 00424e09  8bce                 mov ecx, esi
// 00424e0b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00424e12  e8b9f4ffff           call 0x4242d0
// 00424e17  84c0                 test al, al
// 00424e19  7447                 je 0x424e62
// 00424e1b  8b4710               mov eax, dword ptr [edi + 0x10]
// 00424e1e  c645fc01             mov byte ptr [ebp - 4], 1
// 00424e22  8945ec               mov dword ptr [ebp - 0x14], eax
// 00424e25  39470c               cmp dword ptr [edi + 0xc], eax
// 00424e28  7606                 jbe 0x424e30
// 00424e2a  ff15ace98900         call dword ptr [0x89e9ac]
// 00424e30  8b5f0c               mov ebx, dword ptr [edi + 0xc]
// 00424e33  3b5f10               cmp ebx, dword ptr [edi + 0x10]
// 00424e36  7606                 jbe 0x424e3e
// 00424e38  ff15ace98900         call dword ptr [0x89e9ac]
// 00424e3e  8b460c               mov eax, dword ptr [esi + 0xc]
// 00424e41  c6450800             mov byte ptr [ebp + 8], 0
// 00424e45  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00424e48  8b5508               mov edx, dword ptr [ebp + 8]
// 00424e4b  51                   push ecx
// 00424e4c  52                   push edx
// 00424e4d  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00424e50  8d4e08               lea ecx, [esi + 8]
// 00424e53  51                   push ecx
// 00424e54  50                   push eax
// 00424e55  52                   push edx
// 00424e56  53                   push ebx
// 00424e57  e8a40f0900           call 0x4b5e00
// 00424e5c  83c418               add esp, 0x18
// 00424e5f  894610               mov dword ptr [esi + 0x10], eax
// 00424e62  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00424e65  5f                   pop edi
// 00424e66  8bc6                 mov eax, esi
// 00424e68  5e                   pop esi
// 00424e69  64890d00000000       mov dword ptr fs:[0], ecx
// 00424e70  5b                   pop ebx
// 00424e71  8be5                 mov esp, ebp
// 00424e73  5d                   pop ebp
// 00424e74  c20400               ret 4
// standard library vector<string> (function ??0?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
