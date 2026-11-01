// from server: 100% by auto
// roc 2009-12 00427790  unit: boost::any::H::?$holder  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00427790
//
// 00427790  83ec08               sub esp, 8
// 00427793  56                   push esi
// 00427794  8bf1                 mov esi, ecx
// 00427796  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00427799  57                   push edi
// 0042779a  85c9                 test ecx, ecx
// 0042779c  7504                 jne 0x4277a2
// 0042779e  33c0                 xor eax, eax
// 004277a0  eb08                 jmp 0x4277aa
// 004277a2  8b4614               mov eax, dword ptr [esi + 0x14]
// 004277a5  2bc1                 sub eax, ecx
// 004277a7  c1f803               sar eax, 3
// 004277aa  8b7e10               mov edi, dword ptr [esi + 0x10]
// 004277ad  8bd7                 mov edx, edi
// 004277af  2bd1                 sub edx, ecx
// 004277b1  c1fa03               sar edx, 3
// 004277b4  3bd0                 cmp edx, eax
// 004277b6  7331                 jae 0x4277e9
// 004277b8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004277bc  c644240800           mov byte ptr [esp + 8], 0
// 004277c1  8b442408             mov eax, dword ptr [esp + 8]
// 004277c5  50                   push eax
// 004277c6  8b442418             mov eax, dword ptr [esp + 0x18]
// 004277ca  51                   push ecx
// 004277cb  8d5608               lea edx, [esi + 8]
// 004277ce  52                   push edx
// 004277cf  50                   push eax
// 004277d0  6a01                 push 1
// 004277d2  57                   push edi
// 004277d3  e818f8ffff           call 0x426ff0
// 004277d8  83c418               add esp, 0x18
// 004277db  83c708               add edi, 8
// 004277de  897e10               mov dword ptr [esi + 0x10], edi
// 004277e1  5f                   pop edi
// 004277e2  5e                   pop esi
// 004277e3  83c408               add esp, 8
// 004277e6  c20400               ret 4
// 004277e9  3bcf                 cmp ecx, edi
// 004277eb  7606                 jbe 0x4277f3
// 004277ed  ff1560b79800         call dword ptr [0x98b760]
// 004277f3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004277f7  8b06                 mov eax, dword ptr [esi]
// 004277f9  51                   push ecx
// 004277fa  57                   push edi
// 004277fb  50                   push eax
// 004277fc  8d542414             lea edx, [esp + 0x14]
// 00427800  52                   push edx
// 00427801  8bce                 mov ecx, esi
// 00427803  e8c8feffff           call 0x4276d0
// 00427808  5f                   pop edi
// 00427809  5e                   pop esi
// 0042780a  83c408               add esp, 8
// 0042780d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
