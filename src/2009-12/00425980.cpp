// from server: 100% by auto
// roc 2009-12 00425980  unit: MainLogManager  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00425980
//
// 00425980  55                   push ebp
// 00425981  8bec                 mov ebp, esp
// 00425983  6aff                 push -1
// 00425985  68a8919200           push 0x9291a8
// 0042598a  64a100000000         mov eax, dword ptr fs:[0]
// 00425990  50                   push eax
// 00425991  64892500000000       mov dword ptr fs:[0], esp
// 00425998  83ec0c               sub esp, 0xc
// 0042599b  53                   push ebx
// 0042599c  56                   push esi
// 0042599d  57                   push edi
// 0042599e  8965f0               mov dword ptr [ebp - 0x10], esp
// 004259a1  8bf1                 mov esi, ecx
// 004259a3  6a04                 push 4
// 004259a5  8975e8               mov dword ptr [ebp - 0x18], esi
// 004259a8  e8b3de3c00           call 0x7f3860
// 004259ad  83c404               add esp, 4
// 004259b0  85c0                 test eax, eax
// 004259b2  7404                 je 0x4259b8
// 004259b4  8930                 mov dword ptr [eax], esi
// 004259b6  eb02                 jmp 0x4259ba
// 004259b8  33c0                 xor eax, eax
// 004259ba  8906                 mov dword ptr [esi], eax
// 004259bc  8b7d08               mov edi, dword ptr [ebp + 8]
// 004259bf  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 004259c2  2b4f0c               sub ecx, dword ptr [edi + 0xc]
// 004259c5  b893244992           mov eax, 0x92492493
// 004259ca  f7e9                 imul ecx
// 004259cc  03d1                 add edx, ecx
// 004259ce  c1fa04               sar edx, 4
// 004259d1  8bc2                 mov eax, edx
// 004259d3  c1e81f               shr eax, 0x1f
// 004259d6  03c2                 add eax, edx
// 004259d8  50                   push eax
// 004259d9  8bce                 mov ecx, esi
// 004259db  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004259e2  e8e9f1ffff           call 0x424bd0
// 004259e7  84c0                 test al, al
// 004259e9  7447                 je 0x425a32
// 004259eb  8b4710               mov eax, dword ptr [edi + 0x10]
// 004259ee  c645fc01             mov byte ptr [ebp - 4], 1
// 004259f2  8945ec               mov dword ptr [ebp - 0x14], eax
// 004259f5  39470c               cmp dword ptr [edi + 0xc], eax
// 004259f8  7606                 jbe 0x425a00
// 004259fa  ff1560b79800         call dword ptr [0x98b760]
// 00425a00  8b5f0c               mov ebx, dword ptr [edi + 0xc]
// 00425a03  3b5f10               cmp ebx, dword ptr [edi + 0x10]
// 00425a06  7606                 jbe 0x425a0e
// 00425a08  ff1560b79800         call dword ptr [0x98b760]
// 00425a0e  8b460c               mov eax, dword ptr [esi + 0xc]
// 00425a11  c6450800             mov byte ptr [ebp + 8], 0
// 00425a15  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00425a18  8b5508               mov edx, dword ptr [ebp + 8]
// 00425a1b  51                   push ecx
// 00425a1c  52                   push edx
// 00425a1d  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00425a20  8d4e08               lea ecx, [esi + 8]
// 00425a23  51                   push ecx
// 00425a24  50                   push eax
// 00425a25  52                   push edx
// 00425a26  53                   push ebx
// 00425a27  e8e4290d00           call 0x4f8410
// 00425a2c  83c418               add esp, 0x18
// 00425a2f  894610               mov dword ptr [esi + 0x10], eax
// 00425a32  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00425a35  5f                   pop edi
// 00425a36  8bc6                 mov eax, esi
// 00425a38  5e                   pop esi
// 00425a39  64890d00000000       mov dword ptr fs:[0], ecx
// 00425a40  5b                   pop ebx
// 00425a41  8be5                 mov esp, ebp
// 00425a43  5d                   pop ebp
// 00425a44  c20400               ret 4
// standard library vector<string> (function ??0?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@ABV01@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
