// from server: 100% by auto
// roc 2010-06 0091c2c0  unit: seg_00910000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0091c2c0
//
// 0091c2c0  55                   push ebp
// 0091c2c1  8bec                 mov ebp, esp
// 0091c2c3  83ec10               sub esp, 0x10
// 0091c2c6  33c0                 xor eax, eax
// 0091c2c8  8845ff               mov byte ptr [ebp - 1], al
// 0091c2cb  8a4dfd               mov cl, byte ptr [ebp - 3]
// 0091c2ce  884dfe               mov byte ptr [ebp - 2], cl
// 0091c2d1  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0091c2d4  8955f8               mov dword ptr [ebp - 8], edx
// 0091c2d7  8b4508               mov eax, dword ptr [ebp + 8]
// 0091c2da  8945f0               mov dword ptr [ebp - 0x10], eax
// 0091c2dd  0fb64dff             movzx ecx, byte ptr [ebp - 1]
// 0091c2e1  51                   push ecx
// 0091c2e2  0fb655fe             movzx edx, byte ptr [ebp - 2]
// 0091c2e6  52                   push edx
// 0091c2e7  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0091c2ea  50                   push eax
// 0091c2eb  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0091c2ee  51                   push ecx
// 0091c2ef  8b55f8               mov edx, dword ptr [ebp - 8]
// 0091c2f2  52                   push edx
// 0091c2f3  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 0091c2f6  50                   push eax
// 0091c2f7  e814000000           call 0x91c310
// 0091c2fc  83c418               add esp, 0x18
// 0091c2ff  8be5                 mov esp, ebp
// 0091c301  5d                   pop ebp
// 0091c302  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$unchecked_uninitialized_copy@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@V?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@stdext@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00AAV?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
