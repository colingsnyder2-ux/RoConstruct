// from server: 100% by auto
// roc 2009-06 00532850  unit: RBX::BeveledBlockBuilder  size: 405 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00532850
//
// 00532850  55                   push ebp
// 00532851  8bec                 mov ebp, esp
// 00532853  6aff                 push -1
// 00532855  6890ed8500           push 0x85ed90
// 0053285a  64a100000000         mov eax, dword ptr fs:[0]
// 00532860  50                   push eax
// 00532861  64892500000000       mov dword ptr fs:[0], esp
// 00532868  83ec20               sub esp, 0x20
// 0053286b  53                   push ebx
// 0053286c  56                   push esi
// 0053286d  8bf1                 mov esi, ecx
// 0053286f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00532872  57                   push edi
// 00532873  8965f0               mov dword ptr [ebp - 0x10], esp
// 00532876  85c0                 test eax, eax
// 00532878  7504                 jne 0x53287e
// 0053287a  33c9                 xor ecx, ecx
// 0053287c  eb18                 jmp 0x532896
// 0053287e  8b5614               mov edx, dword ptr [esi + 0x14]
// 00532881  2bd0                 sub edx, eax
// 00532883  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00532888  f7ea                 imul edx
// 0053288a  c1fa02               sar edx, 2
// 0053288d  8bc2                 mov eax, edx
// 0053288f  c1e81f               shr eax, 0x1f
// 00532892  03c2                 add eax, edx
// 00532894  8bc8                 mov ecx, eax
// 00532896  8b7d10               mov edi, dword ptr [ebp + 0x10]
// 00532899  85ff                 test edi, edi
// 0053289b  0f8476020000         je 0x532b17
// 005328a1  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005328a4  8bd3                 mov edx, ebx
// 005328a6  2b560c               sub edx, dword ptr [esi + 0xc]
// 005328a9  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005328ae  f7ea                 imul edx
// 005328b0  c1fa02               sar edx, 2
// 005328b3  8bc2                 mov eax, edx
// 005328b5  c1e81f               shr eax, 0x1f
// 005328b8  03c2                 add eax, edx
// 005328ba  baaaaaaa0a           mov edx, 0xaaaaaaa
// 005328bf  2bd0                 sub edx, eax
// 005328c1  3bd7                 cmp edx, edi
// 005328c3  7305                 jae 0x5328ca
// 005328c5  e896daf5ff           call 0x490360
// 005328ca  8d1438               lea edx, [eax + edi]
// 005328cd  3bca                 cmp ecx, edx
// 005328cf  0f8325010000         jae 0x5329fa
// 005328d5  8bc1                 mov eax, ecx
// 005328d7  d1e8                 shr eax, 1
// 005328d9  bbaaaaaa0a           mov ebx, 0xaaaaaaa
// 005328de  2bd8                 sub ebx, eax
// 005328e0  3bd9                 cmp ebx, ecx
// 005328e2  730c                 jae 0x5328f0
// 005328e4  c745ec00000000       mov dword ptr [ebp - 0x14], 0
// 005328eb  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 005328ee  eb05                 jmp 0x5328f5
// 005328f0  03c8                 add ecx, eax
// 005328f2  894dec               mov dword ptr [ebp - 0x14], ecx
// 005328f5  3bca                 cmp ecx, edx
// 005328f7  7305                 jae 0x5328fe
// 005328f9  8955ec               mov dword ptr [ebp - 0x14], edx
// 005328fc  8bca                 mov ecx, edx
// 005328fe  6a00                 push 0
// 00532900  51                   push ecx
// 00532901  e8faf11800           call 0x6c1b00
// 00532906  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00532909  2b560c               sub edx, dword ptr [esi + 0xc]
// 0053290c  8bc8                 mov ecx, eax
// 0053290e  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00532913  f7ea                 imul edx
// 00532915  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00532918  c1fa02               sar edx, 2
// 0053291b  8bda                 mov ebx, edx
// 0053291d  83c408               add esp, 8
// 00532920  c1eb1f               shr ebx, 0x1f
// 00532923  03da                 add ebx, edx
// 00532925  50                   push eax
// 00532926  8d145b               lea edx, [ebx + ebx*2]
// 00532929  8d04d1               lea eax, [ecx + edx*8]
// 0053292c  57                   push edi
// 0053292d  894d10               mov dword ptr [ebp + 0x10], ecx
// 00532930  50                   push eax
// 00532931  8bce                 mov ecx, esi
// 00532933  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0053293a  e821feffff           call 0x532760
// 0053293f  8b460c               mov eax, dword ptr [esi + 0xc]
// 00532942  c6451400             mov byte ptr [ebp + 0x14], 0
// 00532946  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00532949  52                   push edx
// 0053294a  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0053294d  52                   push edx
// 0053294e  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00532951  8d4e08               lea ecx, [esi + 8]
// 00532954  51                   push ecx
// 00532955  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00532958  51                   push ecx
// 00532959  52                   push edx
// 0053295a  50                   push eax
// 0053295b  e8d0fcffff           call 0x532630
// 00532960  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00532963  8b4610               mov eax, dword ptr [esi + 0x10]
// 00532966  83c418               add esp, 0x18
// 00532969  03df                 add ebx, edi
// 0053296b  8d0c5b               lea ecx, [ebx + ebx*2]
// 0053296e  8d0cca               lea ecx, [edx + ecx*8]
// 00532971  c6451400             mov byte ptr [ebp + 0x14], 0
// 00532975  8b5514               mov edx, dword ptr [ebp + 0x14]
// 00532978  52                   push edx
// 00532979  8b5514               mov edx, dword ptr [ebp + 0x14]
// 0053297c  52                   push edx
// 0053297d  8d5608               lea edx, [esi + 8]
// 00532980  52                   push edx
// 00532981  51                   push ecx
// 00532982  50                   push eax
// 00532983  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00532986  50                   push eax
// 00532987  e8a4fcffff           call 0x532630
// 0053298c  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0053298f  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 00532992  2bcb                 sub ecx, ebx
// 00532994  b8abaaaa2a           mov eax, 0x2aaaaaab
// 00532999  f7e9                 imul ecx
// 0053299b  c1fa02               sar edx, 2
// 0053299e  8bca                 mov ecx, edx
// 005329a0  c1e91f               shr ecx, 0x1f
// 005329a3  03ca                 add ecx, edx
// 005329a5  83c418               add esp, 0x18
// 005329a8  03f9                 add edi, ecx
// 005329aa  85db                 test ebx, ebx
// 005329ac  7409                 je 0x5329b7
// 005329ae  53                   push ebx
// 005329af  e87e601e00           call 0x718a32
// 005329b4  83c404               add esp, 4
// 005329b7  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 005329ba  8d1440               lea edx, [eax + eax*2]
// 005329bd  8b4510               mov eax, dword ptr [ebp + 0x10]
// 005329c0  8d0cd0               lea ecx, [eax + edx*8]
// 005329c3  8d147f               lea edx, [edi + edi*2]
// 005329c6  894e14               mov dword ptr [esi + 0x14], ecx
// 005329c9  8d0cd0               lea ecx, [eax + edx*8]
// 005329cc  894e10               mov dword ptr [esi + 0x10], ecx
// 005329cf  89460c               mov dword ptr [esi + 0xc], eax
// 005329d2  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005329d5  64890d00000000       mov dword ptr fs:[0], ecx
// 005329dc  5f                   pop edi
// 005329dd  5e                   pop esi
// 005329de  5b                   pop ebx
// 005329df  8be5                 mov esp, ebp
// 005329e1  5d                   pop ebp
// 005329e2  c21000               ret 0x10
// standard library vector<pod24> (function ?_Insert_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@IAEXV?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@IABUE@@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
