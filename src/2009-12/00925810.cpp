// from server: 100% by auto
// roc 2009-12 00925810  unit: seg_00920000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00925810
//
// 00925810  55                   push ebp
// 00925811  8bec                 mov ebp, esp
// 00925813  83ec34               sub esp, 0x34
// 00925816  33c0                 xor eax, eax
// 00925818  8845ff               mov byte ptr [ebp - 1], al
// 0092581b  8a4dfd               mov cl, byte ptr [ebp - 3]
// 0092581e  884dfe               mov byte ptr [ebp - 2], cl
// 00925821  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00925824  8955f8               mov dword ptr [ebp - 8], edx
// 00925827  8b4508               mov eax, dword ptr [ebp + 8]
// 0092582a  8945f0               mov dword ptr [ebp - 0x10], eax
// 0092582d  8a4dff               mov cl, byte ptr [ebp - 1]
// 00925830  884dcf               mov byte ptr [ebp - 0x31], cl
// 00925833  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00925836  8955d0               mov dword ptr [ebp - 0x30], edx
// 00925839  8b45d0               mov eax, dword ptr [ebp - 0x30]
// 0092583c  8945d4               mov dword ptr [ebp - 0x2c], eax
// 0092583f  8b4df8               mov ecx, dword ptr [ebp - 8]
// 00925842  894dd8               mov dword ptr [ebp - 0x28], ecx
// 00925845  8b55f0               mov edx, dword ptr [ebp - 0x10]
// 00925848  8955dc               mov dword ptr [ebp - 0x24], edx
// 0092584b  33c0                 xor eax, eax
// 0092584d  8845ef               mov byte ptr [ebp - 0x11], al
// 00925850  8a4ded               mov cl, byte ptr [ebp - 0x13]
// 00925853  884dee               mov byte ptr [ebp - 0x12], cl
// 00925856  8b55d8               mov edx, dword ptr [ebp - 0x28]
// 00925859  8955e8               mov dword ptr [ebp - 0x18], edx
// 0092585c  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0092585f  8945e0               mov dword ptr [ebp - 0x20], eax
// 00925862  0fb64def             movzx ecx, byte ptr [ebp - 0x11]
// 00925866  51                   push ecx
// 00925867  0fb655ee             movzx edx, byte ptr [ebp - 0x12]
// 0092586b  52                   push edx
// 0092586c  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0092586f  50                   push eax
// 00925870  8b4dd4               mov ecx, dword ptr [ebp - 0x2c]
// 00925873  51                   push ecx
// 00925874  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 00925877  52                   push edx
// 00925878  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0092587b  50                   push eax
// 0092587c  e81f080000           call 0x9260a0
// 00925881  83c418               add esp, 0x18
// 00925884  8be5                 mov esp, ebp
// 00925886  5d                   pop ebp
// 00925887  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??$_Unchecked_uninitialized_move@PAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@V?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@stdext@@YAPAVSortedVertex@?$ConvexHull2@M@Wml@@PAV123@00AAV?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
