// from server: 100% by auto
// roc 2008-06 006790b0  unit: Ogre::RbxSceneManagerFactory  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006790b0
//
// 006790b0  56                   push esi
// 006790b1  57                   push edi
// 006790b2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006790b6  8bf1                 mov esi, ecx
// 006790b8  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 006790bf  c7461000000000       mov dword ptr [esi + 0x10], 0
// 006790c6  c7461400000000       mov dword ptr [esi + 0x14], 0
// 006790cd  85ff                 test edi, edi
// 006790cf  7444                 je 0x679115
// 006790d1  81ffffffff3f         cmp edi, 0x3fffffff
// 006790d7  7605                 jbe 0x6790de
// 006790d9  e862dce4ff           call 0x4c6d40
// 006790de  6a00                 push 0
// 006790e0  57                   push edi
// 006790e1  e86a7adaff           call 0x420b50
// 006790e6  8d0cb8               lea ecx, [eax + edi*4]
// 006790e9  83c408               add esp, 8
// 006790ec  894e14               mov dword ptr [esi + 0x14], ecx
// 006790ef  89460c               mov dword ptr [esi + 0xc], eax
// 006790f2  894610               mov dword ptr [esi + 0x10], eax
// 006790f5  8bcf                 mov ecx, edi
// 006790f7  8bd0                 mov edx, eax
// 006790f9  85ff                 test edi, edi
// 006790fb  7612                 jbe 0x67910f
// 006790fd  53                   push ebx
// 006790fe  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00679102  d903                 fld dword ptr [ebx]
// 00679104  49                   dec ecx
// 00679105  d91a                 fstp dword ptr [edx]
// 00679107  83c204               add edx, 4
// 0067910a  85c9                 test ecx, ecx
// 0067910c  77f4                 ja 0x679102
// 0067910e  5b                   pop ebx
// 0067910f  8d14b8               lea edx, [eax + edi*4]
// 00679112  895610               mov dword ptr [esi + 0x10], edx
// 00679115  5f                   pop edi
// 00679116  5e                   pop esi
// 00679117  c20800               ret 8
// standard library vector<float> (function ?_Construct_n@?$vector@MV?$allocator@M@std@@@std@@QAEXIABM@Z)

// stl: vector<float>
typedef float E;
#include <vector>
template class std::vector<E>;
