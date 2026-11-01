// from server: 100% by auto
// roc 2007-03 007161b0  unit: seg_00710000  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007161b0
//
// 007161b0  83ec10               sub esp, 0x10
// 007161b3  56                   push esi
// 007161b4  e8d7ddfdff           call 0x6f3f90
// 007161b9  8b742418             mov esi, dword ptr [esp + 0x18]
// 007161bd  b90d000000           mov ecx, 0xd
// 007161c2  894c240c             mov dword ptr [esp + 0xc], ecx
// 007161c6  894c2410             mov dword ptr [esp + 0x10], ecx
// 007161ca  890e                 mov dword ptr [esi], ecx
// 007161cc  894e04               mov dword ptr [esi + 4], ecx
// 007161cf  56                   push esi
// 007161d0  6a02                 push 2
// 007161d2  33d2                 xor edx, edx
// 007161d4  8d4c240c             lea ecx, [esp + 0xc]
// 007161d8  51                   push ecx
// 007161d9  33c9                 xor ecx, ecx
// 007161db  39542428             cmp dword ptr [esp + 0x28], edx
// 007161df  6a01                 push 1
// 007161e1  0f95c1               setne cl
// 007161e4  89542414             mov dword ptr [esp + 0x14], edx
// 007161e8  89542418             mov dword ptr [esp + 0x18], edx
// 007161ec  83c102               add ecx, 2
// 007161ef  51                   push ecx
// 007161f0  8bc8                 mov ecx, eax
// 007161f2  e8c9b8f6ff           call 0x681ac0
// 007161f7  8bc6                 mov eax, esi
// 007161f9  5e                   pop esi
// 007161fa  83c410               add esp, 0x10
// 007161fd  c20800               ret 8
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectButton.cpp (function ?GetGlyphSize@CXTPSkinObjectButton@@IAE?AVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectButton.cpp
