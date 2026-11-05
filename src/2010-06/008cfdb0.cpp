// from server: 100% by auto
// roc 2010-06 008cfdb0  unit: Ogre::RbxMeshLoader  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008cfdb0
//
// 008cfdb0  83ec08               sub esp, 8
// 008cfdb3  56                   push esi
// 008cfdb4  8bf1                 mov esi, ecx
// 008cfdb6  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008cfdb9  57                   push edi
// 008cfdba  85c9                 test ecx, ecx
// 008cfdbc  7504                 jne 0x8cfdc2
// 008cfdbe  33c0                 xor eax, eax
// 008cfdc0  eb08                 jmp 0x8cfdca
// 008cfdc2  8b4614               mov eax, dword ptr [esi + 0x14]
// 008cfdc5  2bc1                 sub eax, ecx
// 008cfdc7  c1f805               sar eax, 5
// 008cfdca  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008cfdcd  8bd7                 mov edx, edi
// 008cfdcf  2bd1                 sub edx, ecx
// 008cfdd1  c1fa05               sar edx, 5
// 008cfdd4  3bd0                 cmp edx, eax
// 008cfdd6  7331                 jae 0x8cfe09
// 008cfdd8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008cfddc  c644240800           mov byte ptr [esp + 8], 0
// 008cfde1  8b442408             mov eax, dword ptr [esp + 8]
// 008cfde5  50                   push eax
// 008cfde6  8b442418             mov eax, dword ptr [esp + 0x18]
// 008cfdea  51                   push ecx
// 008cfdeb  8d5608               lea edx, [esi + 8]
// 008cfdee  52                   push edx
// 008cfdef  50                   push eax
// 008cfdf0  6a01                 push 1
// 008cfdf2  57                   push edi
// 008cfdf3  e828d9ffff           call 0x8cd720
// 008cfdf8  83c418               add esp, 0x18
// 008cfdfb  83c720               add edi, 0x20
// 008cfdfe  897e10               mov dword ptr [esi + 0x10], edi
// 008cfe01  5f                   pop edi
// 008cfe02  5e                   pop esi
// 008cfe03  83c408               add esp, 8
// 008cfe06  c20400               ret 4
// 008cfe09  3bcf                 cmp ecx, edi
// 008cfe0b  7606                 jbe 0x8cfe13
// 008cfe0d  ff150ca99e00         call dword ptr [0x9ea90c]
// 008cfe13  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008cfe17  8b06                 mov eax, dword ptr [esi]
// 008cfe19  51                   push ecx
// 008cfe1a  57                   push edi
// 008cfe1b  50                   push eax
// 008cfe1c  8d542414             lea edx, [esp + 0x14]
// 008cfe20  52                   push edx
// 008cfe21  8bce                 mov ecx, esi
// 008cfe23  e878f5ffff           call 0x8cf3a0
// 008cfe28  5f                   pop edi
// 008cfe29  5e                   pop esi
// 008cfe2a  83c408               add esp, 8
// 008cfe2d  c20400               ret 4
// standard library vector<pod32> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod32>
struct E { int v[8]; };
#include <vector>
template class std::vector<E>;
