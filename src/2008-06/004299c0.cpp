// from server: 100% by auto
// from server: 100% by auto
// roc 2008-06 004299c0  unit: ThreadLogManager  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004299c0
//
// 004299c0  55                   push ebp
// 004299c1  8bec                 mov ebp, esp
// 004299c3  6aff                 push -1
// 004299c5  68e8f27b00           push 0x7bf2e8
// 004299ca  64a100000000         mov eax, dword ptr fs:[0]
// 004299d0  50                   push eax
// 004299d1  64892500000000       mov dword ptr fs:[0], esp
// 004299d8  83ec0c               sub esp, 0xc
// 004299db  53                   push ebx
// 004299dc  56                   push esi
// 004299dd  57                   push edi
// 004299de  8965f0               mov dword ptr [ebp - 0x10], esp
// 004299e1  8bf1                 mov esi, ecx
// 004299e3  6a04                 push 4
// 004299e5  8975e8               mov dword ptr [ebp - 0x18], esi
// 004299e8  e8336f2700           call 0x6a0920
// 004299ed  83c404               add esp, 4
// 004299f0  85c0                 test eax, eax
// 004299f2  7404                 je 0x4299f8
// 004299f4  8930                 mov dword ptr [eax], esi
// 004299f6  eb02                 jmp 0x4299fa
// 004299f8  33c0                 xor eax, eax
// 004299fa  8906                 mov dword ptr [esi], eax
// 004299fc  8b7d08               mov edi, dword ptr [ebp + 8]
// 004299ff  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 00429a02  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 00429a05  b893244992           mov eax, 0x92492493
// 00429a0a  f7e9                 imul ecx
// 00429a0c  03d1                 add edx, ecx
// 00429a0e  c1fa04               sar edx, 4
// 00429a11  8bc2                 mov eax, edx
// 00429a13  c1e81f               shr eax, 0x1f
// 00429a16  03c2                 add eax, edx
// 00429a18  50                   push eax
// 00429a19  8bce                 mov ecx, esi
// 00429a1b  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00429a22  e829f4ffff           call 0x428e50
// 00429a27  84c0                 test al, al
// 00429a29  7447                 je 0x429a72
// 00429a2b  8b4710               mov eax, dword ptr [edi + 0x10]
// 00429a2e  c645fc01             mov byte ptr [ebp - 4], 1
// 00429a32  8945ec               mov dword ptr [ebp - 0x14], eax
// 00429a35  39470c               cmp dword ptr [edi + 0xc], eax
// 00429a38  7606                 jbe 0x429a40
// 00429a3a  ff1590288000         call dword ptr [0x802890]
// 00429a40  8b5f0c               mov ebx, dword ptr [edi + 0xc]
// 00429a43  3b5f10               cmp ebx, dword ptr [edi + 0x10]
// 00429a46  7606                 jbe 0x429a4e
// 00429a48  ff1590288000         call dword ptr [0x802890]
// 00429a4e  8b460c               mov eax, dword ptr [esi + 0xc]
// 00429a51  c6450800             mov byte ptr [ebp + 8], 0
// 00429a55  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00429a58  8b5508               mov edx, dword ptr [ebp + 8]
// 00429a5b  51                   push ecx
// 00429a5c  52                   push edx
// 00429a5d  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00429a60  8d4e08               lea ecx, [esi + 8]
// 00429a63  51                   push ecx
// 00429a64  50                   push eax
// 00429a65  52                   push edx
// 00429a66  53                   push ebx
// 00429a67  e8b41c0600           call 0x48b720
// 00429a6c  83c418               add esp, 0x18
// 00429a6f  894610               mov dword ptr [esi + 0x10], eax
// 00429a72  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00429a75  5f                   pop edi
// 00429a76  8bc6                 mov eax, esi
// 00429a78  5e                   pop esi
// 00429a79  64890d00000000       mov dword ptr fs:[0], ecx
// 00429a80  5b                   pop ebx
// 00429a81  8be5                 mov esp, ebp
// 00429a83  5d                   pop ebp
// 00429a84  c20400               ret 4
// standard library vector<string> (function ??0?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
