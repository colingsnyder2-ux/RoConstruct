// from server: 100% by auto
// roc 2009-06 00700ca0  unit: RBX::AdornRbxGfx  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00700ca0
//
// 00700ca0  83ec08               sub esp, 8
// 00700ca3  56                   push esi
// 00700ca4  8bf1                 mov esi, ecx
// 00700ca6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00700ca9  57                   push edi
// 00700caa  85c9                 test ecx, ecx
// 00700cac  7504                 jne 0x700cb2
// 00700cae  33c0                 xor eax, eax
// 00700cb0  eb08                 jmp 0x700cba
// 00700cb2  8b4614               mov eax, dword ptr [esi + 0x14]
// 00700cb5  2bc1                 sub eax, ecx
// 00700cb7  c1f803               sar eax, 3
// 00700cba  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00700cbd  8bd7                 mov edx, edi
// 00700cbf  2bd1                 sub edx, ecx
// 00700cc1  c1fa03               sar edx, 3
// 00700cc4  3bd0                 cmp edx, eax
// 00700cc6  7331                 jae 0x700cf9
// 00700cc8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00700ccc  c644240800           mov byte ptr [esp + 8], 0
// 00700cd1  8b442408             mov eax, dword ptr [esp + 8]
// 00700cd5  50                   push eax
// 00700cd6  8b442418             mov eax, dword ptr [esp + 0x18]
// 00700cda  51                   push ecx
// 00700cdb  8d5608               lea edx, [esi + 8]
// 00700cde  52                   push edx
// 00700cdf  50                   push eax
// 00700ce0  6a01                 push 1
// 00700ce2  57                   push edi
// 00700ce3  e8f820d8ff           call 0x482de0
// 00700ce8  83c418               add esp, 0x18
// 00700ceb  83c708               add edi, 8
// 00700cee  897e10               mov dword ptr [esi + 0x10], edi
// 00700cf1  5f                   pop edi
// 00700cf2  5e                   pop esi
// 00700cf3  83c408               add esp, 8
// 00700cf6  c20400               ret 4
// 00700cf9  3bcf                 cmp ecx, edi
// 00700cfb  7606                 jbe 0x700d03
// 00700cfd  ff15ace98900         call dword ptr [0x89e9ac]
// 00700d03  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00700d07  8b06                 mov eax, dword ptr [esi]
// 00700d09  51                   push ecx
// 00700d0a  57                   push edi
// 00700d0b  50                   push eax
// 00700d0c  8d542414             lea edx, [esp + 0x14]
// 00700d10  52                   push edx
// 00700d11  8bce                 mov ecx, esi
// 00700d13  e828dcffff           call 0x6fe940
// 00700d18  5f                   pop edi
// 00700d19  5e                   pop esi
// 00700d1a  83c408               add esp, 8
// 00700d1d  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
