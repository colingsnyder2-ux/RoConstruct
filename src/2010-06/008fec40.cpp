// from server: 100% by auto
// roc 2010-06 008fec40  unit: Ogre::RbxSceneUpdater  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fec40
//
// 008fec40  83ec08               sub esp, 8
// 008fec43  56                   push esi
// 008fec44  8bf1                 mov esi, ecx
// 008fec46  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008fec49  57                   push edi
// 008fec4a  85c9                 test ecx, ecx
// 008fec4c  7504                 jne 0x8fec52
// 008fec4e  33c0                 xor eax, eax
// 008fec50  eb08                 jmp 0x8fec5a
// 008fec52  8b4614               mov eax, dword ptr [esi + 0x14]
// 008fec55  2bc1                 sub eax, ecx
// 008fec57  c1f802               sar eax, 2
// 008fec5a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 008fec5d  8bd7                 mov edx, edi
// 008fec5f  2bd1                 sub edx, ecx
// 008fec61  c1fa02               sar edx, 2
// 008fec64  3bd0                 cmp edx, eax
// 008fec66  7316                 jae 0x8fec7e
// 008fec68  8b442414             mov eax, dword ptr [esp + 0x14]
// 008fec6c  8b08                 mov ecx, dword ptr [eax]
// 008fec6e  890f                 mov dword ptr [edi], ecx
// 008fec70  83c704               add edi, 4
// 008fec73  897e10               mov dword ptr [esi + 0x10], edi
// 008fec76  5f                   pop edi
// 008fec77  5e                   pop esi
// 008fec78  83c408               add esp, 8
// 008fec7b  c20400               ret 4
// 008fec7e  3bcf                 cmp ecx, edi
// 008fec80  7606                 jbe 0x8fec88
// 008fec82  ff150ca99e00         call dword ptr [0x9ea90c]
// 008fec88  8b542414             mov edx, dword ptr [esp + 0x14]
// 008fec8c  8b06                 mov eax, dword ptr [esi]
// 008fec8e  52                   push edx
// 008fec8f  57                   push edi
// 008fec90  50                   push eax
// 008fec91  8d442414             lea eax, [esp + 0x14]
// 008fec95  50                   push eax
// 008fec96  8bce                 mov ecx, esi
// 008fec98  e8f39cfcff           call 0x8c8990
// 008fec9d  5f                   pop edi
// 008fec9e  5e                   pop esi
// 008fec9f  83c408               add esp, 8
// 008feca2  c20400               ret 4
// standard library vector<ptr> (function ?push_back@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXABQAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
