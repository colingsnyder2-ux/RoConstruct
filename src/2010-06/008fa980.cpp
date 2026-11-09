// from server: 100% by auto
// roc 2010-06 008fa980  unit: Ogre::UTVertexPositionNormalStudsTex::?$SpecializedMeshGen  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fa980
//
// 008fa980  83ec08               sub esp, 8
// 008fa983  56                   push esi
// 008fa984  8bf1                 mov esi, ecx
// 008fa986  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008fa989  57                   push edi
// 008fa98a  85c9                 test ecx, ecx
// 008fa98c  7504                 jne 0x8fa992
// 008fa98e  33c0                 xor eax, eax
// 008fa990  eb08                 jmp 0x8fa99a
// 008fa992  8b4614               mov eax, dword ptr [esi + 0x14]
// 008fa995  2bc1                 sub eax, ecx
// 008fa997  c1f805               sar eax, 5
// 008fa99a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008fa99d  8bd7                 mov edx, edi
// 008fa99f  2bd1                 sub edx, ecx
// 008fa9a1  c1fa05               sar edx, 5
// 008fa9a4  3bd0                 cmp edx, eax
// 008fa9a6  7331                 jae 0x8fa9d9
// 008fa9a8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008fa9ac  c644240800           mov byte ptr [esp + 8], 0
// 008fa9b1  8b442408             mov eax, dword ptr [esp + 8]
// 008fa9b5  50                   push eax
// 008fa9b6  8b442418             mov eax, dword ptr [esp + 0x18]
// 008fa9ba  51                   push ecx
// 008fa9bb  8d5608               lea edx, [esi + 8]
// 008fa9be  52                   push edx
// 008fa9bf  50                   push eax
// 008fa9c0  6a01                 push 1
// 008fa9c2  57                   push edi
// 008fa9c3  e8b8b0ffff           call 0x8f5a80
// 008fa9c8  83c418               add esp, 0x18
// 008fa9cb  83c720               add edi, 0x20
// 008fa9ce  897e10               mov dword ptr [esi + 0x10], edi
// 008fa9d1  5f                   pop edi
// 008fa9d2  5e                   pop esi
// 008fa9d3  83c408               add esp, 8
// 008fa9d6  c20400               ret 4
// 008fa9d9  3bcf                 cmp ecx, edi
// 008fa9db  7606                 jbe 0x8fa9e3
// 008fa9dd  ff150ca99e00         call dword ptr [0x9ea90c]
// 008fa9e3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008fa9e7  8b06                 mov eax, dword ptr [esi]
// 008fa9e9  51                   push ecx
// 008fa9ea  57                   push edi
// 008fa9eb  50                   push eax
// 008fa9ec  8d542414             lea edx, [esp + 0x14]
// 008fa9f0  52                   push edx
// 008fa9f1  8bce                 mov ecx, esi
// 008fa9f3  e848caffff           call 0x8f7440
// 008fa9f8  5f                   pop edi
// 008fa9f9  5e                   pop esi
// 008fa9fa  83c408               add esp, 8
// 008fa9fd  c20400               ret 4
// standard library vector<pod32> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
