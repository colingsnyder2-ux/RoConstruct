// from server: 100% by auto
// roc 2009-12 00925f90  unit: seg_00920000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00925f90
//
// 00925f90  55                   push ebp
// 00925f91  8bec                 mov ebp, esp
// 00925f93  83ec10               sub esp, 0x10
// 00925f96  33c0                 xor eax, eax
// 00925f98  8845ff               mov byte ptr [ebp - 1], al
// 00925f9b  8a4dfd               mov cl, byte ptr [ebp - 3]
// 00925f9e  884dfe               mov byte ptr [ebp - 2], cl
// 00925fa1  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00925fa4  8955f8               mov dword ptr [ebp - 8], edx
// 00925fa7  8b4508               mov eax, dword ptr [ebp + 8]
// 00925faa  8945f0               mov dword ptr [ebp - 0x10], eax
// 00925fad  0fb64dff             movzx ecx, byte ptr [ebp - 1]
// 00925fb1  51                   push ecx
// 00925fb2  0fb655fe             movzx edx, byte ptr [ebp - 2]
// 00925fb6  52                   push edx
// 00925fb7  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00925fba  50                   push eax
// 00925fbb  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 00925fbe  51                   push ecx
// 00925fbf  8b55f8               mov edx, dword ptr [ebp - 8]
// 00925fc2  52                   push edx
// 00925fc3  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 00925fc6  50                   push eax
// 00925fc7  e8d4000000           call 0x9260a0
// 00925fcc  83c418               add esp, 0x18
// 00925fcf  8be5                 mov esp, ebp
// 00925fd1  5d                   pop ebp
// 00925fd2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$unchecked_uninitialized_copy@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@V?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@stdext@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00AAV?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
