// from server: 100% by auto
// roc 2010-06 0091c1a0  unit: seg_00910000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0091c1a0
//
// 0091c1a0  55                   push ebp
// 0091c1a1  8bec                 mov ebp, esp
// 0091c1a3  83ec34               sub esp, 0x34
// 0091c1a6  33c0                 xor eax, eax
// 0091c1a8  8845ff               mov byte ptr [ebp - 1], al
// 0091c1ab  8a4dfd               mov cl, byte ptr [ebp - 3]
// 0091c1ae  884dfe               mov byte ptr [ebp - 2], cl
// 0091c1b1  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0091c1b4  8955f8               mov dword ptr [ebp - 8], edx
// 0091c1b7  8b4508               mov eax, dword ptr [ebp + 8]
// 0091c1ba  8945f0               mov dword ptr [ebp - 0x10], eax
// 0091c1bd  8a4dff               mov cl, byte ptr [ebp - 1]
// 0091c1c0  884dcf               mov byte ptr [ebp - 0x31], cl
// 0091c1c3  8b5510               mov edx, dword ptr [ebp + 0x10]
// 0091c1c6  8955d0               mov dword ptr [ebp - 0x30], edx
// 0091c1c9  8b45d0               mov eax, dword ptr [ebp - 0x30]
// 0091c1cc  8945d4               mov dword ptr [ebp - 0x2c], eax
// 0091c1cf  8b4df8               mov ecx, dword ptr [ebp - 8]
// 0091c1d2  894dd8               mov dword ptr [ebp - 0x28], ecx
// 0091c1d5  8b55f0               mov edx, dword ptr [ebp - 0x10]
// 0091c1d8  8955dc               mov dword ptr [ebp - 0x24], edx
// 0091c1db  33c0                 xor eax, eax
// 0091c1dd  8845ef               mov byte ptr [ebp - 0x11], al
// 0091c1e0  8a4ded               mov cl, byte ptr [ebp - 0x13]
// 0091c1e3  884dee               mov byte ptr [ebp - 0x12], cl
// 0091c1e6  8b55d8               mov edx, dword ptr [ebp - 0x28]
// 0091c1e9  8955e8               mov dword ptr [ebp - 0x18], edx
// 0091c1ec  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0091c1ef  8945e0               mov dword ptr [ebp - 0x20], eax
// 0091c1f2  0fb64def             movzx ecx, byte ptr [ebp - 0x11]
// 0091c1f6  51                   push ecx
// 0091c1f7  0fb655ee             movzx edx, byte ptr [ebp - 0x12]
// 0091c1fb  52                   push edx
// 0091c1fc  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0091c1ff  50                   push eax
// 0091c200  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 0091c203  51                   push ecx
// 0091c204  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 0091c207  52                   push edx
// 0091c208  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0091c20b  50                   push eax
// 0091c20c  e8ff000000           call 0x91c310
// 0091c211  83c418               add esp, 0x18
// 0091c214  8be5                 mov esp, ebp
// 0091c216  5d                   pop ebp
// 0091c217  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Unchecked_uninitialized_move@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@V?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@stdext@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00AAV?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
