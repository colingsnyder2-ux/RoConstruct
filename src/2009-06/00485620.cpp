// from server: 100% by auto
// roc 2009-06 00485620  unit: RBX::MeshFileKey  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00485620
//
// 00485620  55                   push ebp
// 00485621  8bec                 mov ebp, esp
// 00485623  6aff                 push -1
// 00485625  68a8538500           push 0x8553a8
// 0048562a  64a100000000         mov eax, dword ptr fs:[0]
// 00485630  50                   push eax
// 00485631  64892500000000       mov dword ptr fs:[0], esp
// 00485638  83ec0c               sub esp, 0xc
// 0048563b  53                   push ebx
// 0048563c  56                   push esi
// 0048563d  57                   push edi
// 0048563e  8965f0               mov dword ptr [ebp - 0x10], esp
// 00485641  8bf1                 mov esi, ecx
// 00485643  6a04                 push 4
// 00485645  8975e8               mov dword ptr [ebp - 0x18], esi
// 00485648  e8eb332900           call 0x718a38
// 0048564d  33c9                 xor ecx, ecx
// 0048564f  83c404               add esp, 4
// 00485652  3bc1                 cmp eax, ecx
// 00485654  7404                 je 0x48565a
// 00485656  8930                 mov dword ptr [eax], esi
// 00485658  eb02                 jmp 0x48565c
// 0048565a  33c0                 xor eax, eax
// 0048565c  8906                 mov dword ptr [esi], eax
// 0048565e  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00485661  8b7b10               mov edi, dword ptr [ebx + 0x10]
// 00485664  2b7b0c               sub edi, dword ptr [ebx + 0xc]
// 00485667  894dfc               mov dword ptr [ebp - 4], ecx
// 0048566a  c1ff03               sar edi, 3
// 0048566d  894e0c               mov dword ptr [esi + 0xc], ecx
// 00485670  894e10               mov dword ptr [esi + 0x10], ecx
// 00485673  894e14               mov dword ptr [esi + 0x14], ecx
// 00485676  3bf9                 cmp edi, ecx
// 00485678  746a                 je 0x4856e4
// 0048567a  81ffffffff1f         cmp edi, 0x1fffffff
// 00485680  7605                 jbe 0x485687
// 00485682  e8d9ac0000           call 0x490360
// 00485687  51                   push ecx
// 00485688  57                   push edi
// 00485689  e862f8ffff           call 0x484ef0
// 0048568e  89460c               mov dword ptr [esi + 0xc], eax
// 00485691  894610               mov dword ptr [esi + 0x10], eax
// 00485694  8d04f8               lea eax, [eax + edi*8]
// 00485697  894614               mov dword ptr [esi + 0x14], eax
// 0048569a  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0048569d  83c408               add esp, 8
// 004856a0  c645fc01             mov byte ptr [ebp - 4], 1
// 004856a4  8945ec               mov dword ptr [ebp - 0x14], eax
// 004856a7  39430c               cmp dword ptr [ebx + 0xc], eax
// 004856aa  7606                 jbe 0x4856b2
// 004856ac  ff15ace98900         call dword ptr [0x89e9ac]
// 004856b2  8b7b0c               mov edi, dword ptr [ebx + 0xc]
// 004856b5  3b7b10               cmp edi, dword ptr [ebx + 0x10]
// 004856b8  7606                 jbe 0x4856c0
// 004856ba  ff15ace98900         call dword ptr [0x89e9ac]
// 004856c0  8b460c               mov eax, dword ptr [esi + 0xc]
// 004856c3  c6450800             mov byte ptr [ebp + 8], 0
// 004856c7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004856ca  8b5508               mov edx, dword ptr [ebp + 8]
// 004856cd  51                   push ecx
// 004856ce  52                   push edx
// 004856cf  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004856d2  8d4e08               lea ecx, [esi + 8]
// 004856d5  51                   push ecx
// 004856d6  50                   push eax
// 004856d7  52                   push edx
// 004856d8  57                   push edi
// 004856d9  e832080000           call 0x485f10
// 004856de  83c418               add esp, 0x18
// 004856e1  894610               mov dword ptr [esi + 0x10], eax
// 004856e4  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004856e7  5f                   pop edi
// 004856e8  8bc6                 mov eax, esi
// 004856ea  5e                   pop esi
// 004856eb  64890d00000000       mov dword ptr fs:[0], ecx
// 004856f2  5b                   pop ebx
// 004856f3  8be5                 mov esp, ebp
// 004856f5  5d                   pop ebp
// 004856f6  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
