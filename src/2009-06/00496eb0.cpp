// from server: 100% by auto
// roc 2009-06 00496eb0  unit: Ogre::TwoDManager  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00496eb0
//
// 00496eb0  83ec10               sub esp, 0x10
// 00496eb3  8b442418             mov eax, dword ptr [esp + 0x18]
// 00496eb7  8b5004               mov edx, dword ptr [eax + 4]
// 00496eba  53                   push ebx
// 00496ebb  55                   push ebp
// 00496ebc  56                   push esi
// 00496ebd  8bf1                 mov esi, ecx
// 00496ebf  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 00496ec2  8b08                 mov ecx, dword ptr [eax]
// 00496ec4  57                   push edi
// 00496ec5  894c2410             mov dword ptr [esp + 0x10], ecx
// 00496ec9  89542414             mov dword ptr [esp + 0x14], edx
// 00496ecd  395e0c               cmp dword ptr [esi + 0xc], ebx
// 00496ed0  7606                 jbe 0x496ed8
// 00496ed2  ff15ace98900         call dword ptr [0x89e9ac]
// 00496ed8  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00496edb  8b2e                 mov ebp, dword ptr [esi]
// 00496edd  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00496ee0  7606                 jbe 0x496ee8
// 00496ee2  ff15ace98900         call dword ptr [0x89e9ac]
// 00496ee8  8b06                 mov eax, dword ptr [esi]
// 00496eea  53                   push ebx
// 00496eeb  55                   push ebp
// 00496eec  57                   push edi
// 00496eed  50                   push eax
// 00496eee  8d442428             lea eax, [esp + 0x28]
// 00496ef2  50                   push eax
// 00496ef3  8bce                 mov ecx, esi
// 00496ef5  e896c0feff           call 0x482f90
// 00496efa  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 00496efd  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 00496f00  7606                 jbe 0x496f08
// 00496f02  ff15ace98900         call dword ptr [0x89e9ac]
// 00496f08  8b542424             mov edx, dword ptr [esp + 0x24]
// 00496f0c  8b06                 mov eax, dword ptr [esi]
// 00496f0e  8d4c2410             lea ecx, [esp + 0x10]
// 00496f12  51                   push ecx
// 00496f13  52                   push edx
// 00496f14  57                   push edi
// 00496f15  50                   push eax
// 00496f16  8bce                 mov ecx, esi
// 00496f18  e873c2feff           call 0x483190
// 00496f1d  5f                   pop edi
// 00496f1e  5e                   pop esi
// 00496f1f  5d                   pop ebp
// 00496f20  5b                   pop ebx
// 00496f21  83c410               add esp, 0x10
// 00496f24  c20800               ret 8
// standard library vector<i64> (function ?_Assign_n@?$vector@_JV?$allocator@_J@std@@@std@@IAEXIAB_J@Z)

// stl: vector<i64>
typedef __int64 E;
#include <vector>
template class std::vector<E>;
