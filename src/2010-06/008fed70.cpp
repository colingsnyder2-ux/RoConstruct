// from server: 100% by auto
// roc 2010-06 008fed70  unit: Ogre::RbxSceneUpdater  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fed70
//
// 008fed70  83ec10               sub esp, 0x10
// 008fed73  8b442418             mov eax, dword ptr [esp + 0x18]
// 008fed77  8b5004               mov edx, dword ptr [eax + 4]
// 008fed7a  53                   push ebx
// 008fed7b  55                   push ebp
// 008fed7c  56                   push esi
// 008fed7d  8bf1                 mov esi, ecx
// 008fed7f  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008fed82  8b08                 mov ecx, dword ptr [eax]
// 008fed84  57                   push edi
// 008fed85  894c2410             mov dword ptr [esp + 0x10], ecx
// 008fed89  89542414             mov dword ptr [esp + 0x14], edx
// 008fed8d  395e0c               cmp dword ptr [esi + 0xc], ebx
// 008fed90  7606                 jbe 0x8fed98
// 008fed92  ff150ca99e00         call dword ptr [0x9ea90c]
// 008fed98  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008fed9b  8b2e                 mov ebp, dword ptr [esi]
// 008fed9d  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 008feda0  7606                 jbe 0x8feda8
// 008feda2  ff150ca99e00         call dword ptr [0x9ea90c]
// 008feda8  8b06                 mov eax, dword ptr [esi]
// 008fedaa  53                   push ebx
// 008fedab  55                   push ebp
// 008fedac  57                   push edi
// 008fedad  50                   push eax
// 008fedae  8d442428             lea eax, [esp + 0x28]
// 008fedb2  50                   push eax
// 008fedb3  8bce                 mov ecx, esi
// 008fedb5  e806320600           call 0x961fc0
// 008fedba  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 008fedbd  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 008fedc0  7606                 jbe 0x8fedc8
// 008fedc2  ff150ca99e00         call dword ptr [0x9ea90c]
// 008fedc8  8b542424             mov edx, dword ptr [esp + 0x24]
// 008fedcc  8b06                 mov eax, dword ptr [esi]
// 008fedce  8d4c2410             lea ecx, [esp + 0x10]
// 008fedd2  51                   push ecx
// 008fedd3  52                   push edx
// 008fedd4  57                   push edi
// 008fedd5  50                   push eax
// 008fedd6  8bce                 mov ecx, esi
// 008fedd8  e84391d5ff           call 0x657f20
// 008feddd  5f                   pop edi
// 008fedde  5e                   pop esi
// 008feddf  5d                   pop ebp
// 008fede0  5b                   pop ebx
// 008fede1  83c410               add esp, 0x10
// 008fede4  c20800               ret 8
// standard library vector<i64> (function ?_Assign_n@?$vector@_JV?$allocator@_J@std@@@std@@IAEXIAB_J@Z)

// stl: vector<i64>
typedef __int64 E;
#include <vector>
template class std::vector<E>;
