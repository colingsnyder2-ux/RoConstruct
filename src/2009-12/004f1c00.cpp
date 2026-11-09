// from server: 100% by auto
// roc 2009-12 004f1c00  unit: seg_004f0000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004f1c00
//
// 004f1c00  55                   push ebp
// 004f1c01  8bec                 mov ebp, esp
// 004f1c03  83ec34               sub esp, 0x34
// 004f1c06  33c0                 xor eax, eax
// 004f1c08  8845ff               mov byte ptr [ebp - 1], al
// 004f1c0b  8a4dfd               mov cl, byte ptr [ebp - 3]
// 004f1c0e  884dfe               mov byte ptr [ebp - 2], cl
// 004f1c11  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004f1c14  8955f8               mov dword ptr [ebp - 8], edx
// 004f1c17  8b4508               mov eax, dword ptr [ebp + 8]
// 004f1c1a  8945f0               mov dword ptr [ebp - 0x10], eax
// 004f1c1d  8a4dff               mov cl, byte ptr [ebp - 1]
// 004f1c20  884dcf               mov byte ptr [ebp - 0x31], cl
// 004f1c23  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004f1c26  8955d0               mov dword ptr [ebp - 0x30], edx
// 004f1c29  8b45d0               mov eax, dword ptr [ebp - 0x30]
// 004f1c2c  8945d4               mov dword ptr [ebp - 0x2c], eax
// 004f1c2f  8b4df8               mov ecx, dword ptr [ebp - 8]
// 004f1c32  894dd8               mov dword ptr [ebp - 0x28], ecx
// 004f1c35  8b55f0               mov edx, dword ptr [ebp - 0x10]
// 004f1c38  8955dc               mov dword ptr [ebp - 0x24], edx
// 004f1c3b  33c0                 xor eax, eax
// 004f1c3d  8845ef               mov byte ptr [ebp - 0x11], al
// 004f1c40  8a4ded               mov cl, byte ptr [ebp - 0x13]
// 004f1c43  884dee               mov byte ptr [ebp - 0x12], cl
// 004f1c46  8b55d8               mov edx, dword ptr [ebp - 0x28]
// 004f1c49  8955e8               mov dword ptr [ebp - 0x18], edx
// 004f1c4c  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 004f1c4f  8945e0               mov dword ptr [ebp - 0x20], eax
// 004f1c52  0fb64def             movzx ecx, byte ptr [ebp - 0x11]
// 004f1c56  51                   push ecx
// 004f1c57  0fb655ee             movzx edx, byte ptr [ebp - 0x12]
// 004f1c5b  52                   push edx
// 004f1c5c  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004f1c5f  50                   push eax
// 004f1c60  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 004f1c63  51                   push ecx
// 004f1c64  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 004f1c67  52                   push edx
// 004f1c68  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 004f1c6b  50                   push eax
// 004f1c6c  e8ff000000           call 0x4f1d70
// 004f1c71  83c418               add esp, 0x18
// 004f1c74  8be5                 mov esp, ebp
// 004f1c76  5d                   pop ebp
// 004f1c77  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Unchecked_uninitialized_move@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@V?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@stdext@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00AAV?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
