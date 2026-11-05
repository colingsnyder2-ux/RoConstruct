// from server: 100% by auto
// roc 2009-12 00925fe0  unit: seg_00920000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00925fe0
//
// 00925fe0  55                   push ebp
// 00925fe1  8bec                 mov ebp, esp
// 00925fe3  83ec10               sub esp, 0x10
// 00925fe6  33c0                 xor eax, eax
// 00925fe8  8845ff               mov byte ptr [ebp - 1], al
// 00925feb  8a4dfd               mov cl, byte ptr [ebp - 3]
// 00925fee  884dfe               mov byte ptr [ebp - 2], cl
// 00925ff1  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00925ff4  8955f8               mov dword ptr [ebp - 8], edx
// 00925ff7  8b4508               mov eax, dword ptr [ebp + 8]
// 00925ffa  8945f0               mov dword ptr [ebp - 0x10], eax
// 00925ffd  0fb64dff             movzx ecx, byte ptr [ebp - 1]
// 00926001  51                   push ecx
// 00926002  0fb655fe             movzx edx, byte ptr [ebp - 2]
// 00926006  52                   push edx
// 00926007  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0092600a  50                   push eax
// 0092600b  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 0092600e  51                   push ecx
// 0092600f  8b55f8               mov edx, dword ptr [ebp - 8]
// 00926012  52                   push edx
// 00926013  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 00926016  50                   push eax
// 00926017  e844010000           call 0x926160
// 0092601c  83c418               add esp, 0x18
// 0092601f  8be5                 mov esp, ebp
// 00926021  5d                   pop ebp
// 00926022  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$unchecked_uninitialized_copy@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@V?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@stdext@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00AAV?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
