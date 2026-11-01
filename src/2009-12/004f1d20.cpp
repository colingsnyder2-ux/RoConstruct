// from server: 100% by auto
// roc 2009-12 004f1d20  unit: seg_004f0000  size: 67 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004f1d20
//
// 004f1d20  55                   push ebp
// 004f1d21  8bec                 mov ebp, esp
// 004f1d23  83ec10               sub esp, 0x10
// 004f1d26  33c0                 xor eax, eax
// 004f1d28  8845ff               mov byte ptr [ebp - 1], al
// 004f1d2b  8a4dfd               mov cl, byte ptr [ebp - 3]
// 004f1d2e  884dfe               mov byte ptr [ebp - 2], cl
// 004f1d31  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004f1d34  8955f8               mov dword ptr [ebp - 8], edx
// 004f1d37  8b4508               mov eax, dword ptr [ebp + 8]
// 004f1d3a  8945f0               mov dword ptr [ebp - 0x10], eax
// 004f1d3d  0fb64dff             movzx ecx, byte ptr [ebp - 1]
// 004f1d41  51                   push ecx
// 004f1d42  0fb655fe             movzx edx, byte ptr [ebp - 2]
// 004f1d46  52                   push edx
// 004f1d47  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004f1d4a  50                   push eax
// 004f1d4b  8b4d10               mov ecx, dword ptr [ebp + 0x10]
// 004f1d4e  51                   push ecx
// 004f1d4f  8b55f8               mov edx, dword ptr [ebp - 8]
// 004f1d52  52                   push edx
// 004f1d53  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004f1d56  50                   push eax
// 004f1d57  e814000000           call 0x4f1d70
// 004f1d5c  83c418               add esp, 0x18
// 004f1d5f  8be5                 mov esp, ebp
// 004f1d61  5d                   pop ebp
// 004f1d62  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$unchecked_uninitialized_copy@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@V?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@stdext@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00AAV?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
