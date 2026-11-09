// from server: 100% by auto
// roc 2010-06 009059b0  unit: Ogre::RbxSpatialHashedSceneNode  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009059b0
//
// 009059b0  83ec08               sub esp, 8
// 009059b3  56                   push esi
// 009059b4  8bf1                 mov esi, ecx
// 009059b6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 009059b9  57                   push edi
// 009059ba  85c9                 test ecx, ecx
// 009059bc  7504                 jne 0x9059c2
// 009059be  33c0                 xor eax, eax
// 009059c0  eb08                 jmp 0x9059ca
// 009059c2  8b4614               mov eax, dword ptr [esi + 0x14]
// 009059c5  2bc1                 sub eax, ecx
// 009059c7  c1f804               sar eax, 4
// 009059ca  8b7e10               mov edi, dword ptr [esi + 0x10]
// 009059cd  8bd7                 mov edx, edi
// 009059cf  2bd1                 sub edx, ecx
// 009059d1  c1fa04               sar edx, 4
// 009059d4  3bd0                 cmp edx, eax
// 009059d6  7331                 jae 0x905a09
// 009059d8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 009059dc  c644240800           mov byte ptr [esp + 8], 0
// 009059e1  8b442408             mov eax, dword ptr [esp + 8]
// 009059e5  50                   push eax
// 009059e6  8b442418             mov eax, dword ptr [esp + 0x18]
// 009059ea  51                   push ecx
// 009059eb  8d5608               lea edx, [esi + 8]
// 009059ee  52                   push edx
// 009059ef  50                   push eax
// 009059f0  6a01                 push 1
// 009059f2  57                   push edi
// 009059f3  e8a8ebffff           call 0x9045a0
// 009059f8  83c418               add esp, 0x18
// 009059fb  83c710               add edi, 0x10
// 009059fe  897e10               mov dword ptr [esi + 0x10], edi
// 00905a01  5f                   pop edi
// 00905a02  5e                   pop esi
// 00905a03  83c408               add esp, 8
// 00905a06  c20400               ret 4
// 00905a09  3bcf                 cmp ecx, edi
// 00905a0b  7606                 jbe 0x905a13
// 00905a0d  ff150ca99e00         call dword ptr [0x9ea90c]
// 00905a13  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00905a17  8b06                 mov eax, dword ptr [esi]
// 00905a19  51                   push ecx
// 00905a1a  57                   push edi
// 00905a1b  50                   push eax
// 00905a1c  8d542414             lea edx, [esp + 0x14]
// 00905a20  52                   push edx
// 00905a21  8bce                 mov ecx, esi
// 00905a23  e8d8fbffff           call 0x905600
// 00905a28  5f                   pop edi
// 00905a29  5e                   pop esi
// 00905a2a  83c408               add esp, 8
// 00905a2d  c20400               ret 4
// standard library vector<pod16> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
