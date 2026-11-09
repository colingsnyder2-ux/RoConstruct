// from server: 100% by auto
// roc 2009-12 00925940  unit: seg_00920000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00925940
//
// 00925940  55                   push ebp
// 00925941  8bec                 mov ebp, esp
// 00925943  83ec34               sub esp, 0x34
// 00925946  33c0                 xor eax, eax
// 00925948  8845ff               mov byte ptr [ebp - 1], al
// 0092594b  8a4dfd               mov cl, byte ptr [ebp - 3]
// 0092594e  884dfe               mov byte ptr [ebp - 2], cl
// 00925951  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00925954  8955f8               mov dword ptr [ebp - 8], edx
// 00925957  8b4508               mov eax, dword ptr [ebp + 8]
// 0092595a  8945f0               mov dword ptr [ebp - 0x10], eax
// 0092595d  8a4dff               mov cl, byte ptr [ebp - 1]
// 00925960  884dcf               mov byte ptr [ebp - 0x31], cl
// 00925963  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00925966  8955d0               mov dword ptr [ebp - 0x30], edx
// 00925969  8b45d0               mov eax, dword ptr [ebp - 0x30]
// 0092596c  8945d4               mov dword ptr [ebp - 0x2c], eax
// 0092596f  8b4df8               mov ecx, dword ptr [ebp - 8]
// 00925972  894dd8               mov dword ptr [ebp - 0x28], ecx
// 00925975  8b55f0               mov edx, dword ptr [ebp - 0x10]
// 00925978  8955dc               mov dword ptr [ebp - 0x24], edx
// 0092597b  33c0                 xor eax, eax
// 0092597d  8845ef               mov byte ptr [ebp - 0x11], al
// 00925980  8a4ded               mov cl, byte ptr [ebp - 0x13]
// 00925983  884dee               mov byte ptr [ebp - 0x12], cl
// 00925986  8b55d8               mov edx, dword ptr [ebp - 0x28]
// 00925989  8955e8               mov dword ptr [ebp - 0x18], edx
// 0092598c  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0092598f  8945e0               mov dword ptr [ebp - 0x20], eax
// 00925992  0fb64def             movzx ecx, byte ptr [ebp - 0x11]
// 00925996  51                   push ecx
// 00925997  0fb655ee             movzx edx, byte ptr [ebp - 0x12]
// 0092599b  52                   push edx
// 0092599c  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0092599f  50                   push eax
// 009259a0  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 009259a3  51                   push ecx
// 009259a4  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 009259a7  52                   push edx
// 009259a8  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 009259ab  50                   push eax
// 009259ac  e8af070000           call 0x926160
// 009259b1  83c418               add esp, 0x18
// 009259b4  8be5                 mov esp, ebp
// 009259b6  5d                   pop ebp
// 009259b7  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Unchecked_uninitialized_move@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@V?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@stdext@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00AAV?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
