// from server: 100% by auto
// roc 2008-06 0065b430  unit: RBX::BallBallContact  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0065b430
//
// 0065b430  83ec18               sub esp, 0x18
// 0065b433  53                   push ebx
// 0065b434  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0065b438  56                   push esi
// 0065b439  8bf1                 mov esi, ecx
// 0065b43b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0065b43e  57                   push edi
// 0065b43f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0065b442  8bc7                 mov eax, edi
// 0065b444  2bc1                 sub eax, ecx
// 0065b446  c1f803               sar eax, 3
// 0065b449  3bd8                 cmp ebx, eax
// 0065b44b  762f                 jbe 0x65b47c
// 0065b44d  3bcf                 cmp ecx, edi
// 0065b44f  7606                 jbe 0x65b457
// 0065b451  ff1590288000         call dword ptr [0x802890]
// 0065b457  8b5610               mov edx, dword ptr [esi + 0x10]
// 0065b45a  2b560c               sub edx, dword ptr [esi + 0xc]
// 0065b45d  8b06                 mov eax, dword ptr [esi]
// 0065b45f  8d4c242c             lea ecx, [esp + 0x2c]
// 0065b463  51                   push ecx
// 0065b464  c1fa03               sar edx, 3
// 0065b467  2bda                 sub ebx, edx
// 0065b469  53                   push ebx
// 0065b46a  57                   push edi
// 0065b46b  50                   push eax
// 0065b46c  8bce                 mov ecx, esi
// 0065b46e  e80dfbffff           call 0x65af80
// 0065b473  5f                   pop edi
// 0065b474  5e                   pop esi
// 0065b475  5b                   pop ebx
// 0065b476  83c418               add esp, 0x18
// 0065b479  c20c00               ret 0xc
// 0065b47c  7352                 jae 0x65b4d0
// 0065b47e  3bcf                 cmp ecx, edi
// 0065b480  7606                 jbe 0x65b488
// 0065b482  ff1590288000         call dword ptr [0x802890]
// 0065b488  8b06                 mov eax, dword ptr [esi]
// 0065b48a  55                   push ebp
// 0065b48b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0065b48e  89442418             mov dword ptr [esp + 0x18], eax
// 0065b492  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0065b495  7606                 jbe 0x65b49d
// 0065b497  ff1590288000         call dword ptr [0x802890]
// 0065b49d  8b0e                 mov ecx, dword ptr [esi]
// 0065b49f  53                   push ebx
// 0065b4a0  8d542424             lea edx, [esp + 0x24]
// 0065b4a4  894c2414             mov dword ptr [esp + 0x14], ecx
// 0065b4a8  52                   push edx
// 0065b4a9  8d4c2418             lea ecx, [esp + 0x18]
// 0065b4ad  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0065b4b1  e85a140200           call 0x67c910
// 0065b4b6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0065b4ba  8b5004               mov edx, dword ptr [eax + 4]
// 0065b4bd  8b00                 mov eax, dword ptr [eax]
// 0065b4bf  57                   push edi
// 0065b4c0  51                   push ecx
// 0065b4c1  52                   push edx
// 0065b4c2  50                   push eax
// 0065b4c3  8d4c2428             lea ecx, [esp + 0x28]
// 0065b4c7  51                   push ecx
// 0065b4c8  8bce                 mov ecx, esi
// 0065b4ca  e811faffff           call 0x65aee0
// 0065b4cf  5d                   pop ebp
// 0065b4d0  5f                   pop edi
// 0065b4d1  5e                   pop esi
// 0065b4d2  5b                   pop ebx
// 0065b4d3  83c418               add esp, 0x18
// 0065b4d6  c20c00               ret 0xc
// standard library vector<pod8> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
