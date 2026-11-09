// from server: 100% by auto
// roc 2009-06 0047fe10  unit: RBX::VHumanoid::?$FactoryProduct::Creator  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047fe10
//
// 0047fe10  83ec08               sub esp, 8
// 0047fe13  56                   push esi
// 0047fe14  8bf1                 mov esi, ecx
// 0047fe16  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0047fe19  57                   push edi
// 0047fe1a  85c9                 test ecx, ecx
// 0047fe1c  7504                 jne 0x47fe22
// 0047fe1e  33c0                 xor eax, eax
// 0047fe20  eb08                 jmp 0x47fe2a
// 0047fe22  8b4614               mov eax, dword ptr [esi + 0x14]
// 0047fe25  2bc1                 sub eax, ecx
// 0047fe27  c1f803               sar eax, 3
// 0047fe2a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0047fe2d  8bd7                 mov edx, edi
// 0047fe2f  2bd1                 sub edx, ecx
// 0047fe31  c1fa03               sar edx, 3
// 0047fe34  3bd0                 cmp edx, eax
// 0047fe36  7331                 jae 0x47fe69
// 0047fe38  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0047fe3c  c644240800           mov byte ptr [esp + 8], 0
// 0047fe41  8b442408             mov eax, dword ptr [esp + 8]
// 0047fe45  50                   push eax
// 0047fe46  8b442418             mov eax, dword ptr [esp + 0x18]
// 0047fe4a  51                   push ecx
// 0047fe4b  8d5608               lea edx, [esi + 8]
// 0047fe4e  52                   push edx
// 0047fe4f  50                   push eax
// 0047fe50  6a01                 push 1
// 0047fe52  57                   push edi
// 0047fe53  e858e2ffff           call 0x47e0b0
// 0047fe58  83c418               add esp, 0x18
// 0047fe5b  83c708               add edi, 8
// 0047fe5e  897e10               mov dword ptr [esi + 0x10], edi
// 0047fe61  5f                   pop edi
// 0047fe62  5e                   pop esi
// 0047fe63  83c408               add esp, 8
// 0047fe66  c20400               ret 4
// 0047fe69  3bcf                 cmp ecx, edi
// 0047fe6b  7606                 jbe 0x47fe73
// 0047fe6d  ff15ace98900         call dword ptr [0x89e9ac]
// 0047fe73  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0047fe77  8b06                 mov eax, dword ptr [esi]
// 0047fe79  51                   push ecx
// 0047fe7a  57                   push edi
// 0047fe7b  50                   push eax
// 0047fe7c  8d542414             lea edx, [esp + 0x14]
// 0047fe80  52                   push edx
// 0047fe81  8bce                 mov ecx, esi
// 0047fe83  e8d8f5ffff           call 0x47f460
// 0047fe88  5f                   pop edi
// 0047fe89  5e                   pop esi
// 0047fe8a  83c408               add esp, 8
// 0047fe8d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
