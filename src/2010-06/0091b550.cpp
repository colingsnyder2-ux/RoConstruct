// from server: 100% by auto
// roc 2010-06 0091b550  unit: RBX::GfxAttachement  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0091b550
//
// 0091b550  55                   push ebp
// 0091b551  8bec                 mov ebp, esp
// 0091b553  83ec24               sub esp, 0x24
// 0091b556  894ddc               mov dword ptr [ebp - 0x24], ecx
// 0091b559  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0091b55c  83780c00             cmp dword ptr [eax + 0xc], 0
// 0091b560  746d                 je 0x91b5cf
// 0091b562  8b4ddc               mov ecx, dword ptr [ebp - 0x24]
// 0091b565  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0091b568  8955e8               mov dword ptr [ebp - 0x18], edx
// 0091b56b  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0091b56e  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0091b571  894dec               mov dword ptr [ebp - 0x14], ecx
// 0091b574  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 0091b577  8955f0               mov dword ptr [ebp - 0x10], edx
// 0091b57a  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0091b57d  8945f4               mov dword ptr [ebp - 0xc], eax
// 0091b580  8a4dfe               mov cl, byte ptr [ebp - 2]
// 0091b583  884dff               mov byte ptr [ebp - 1], cl
// 0091b586  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 0091b589  8955f8               mov dword ptr [ebp - 8], edx
// 0091b58c  eb09                 jmp 0x91b597
// 0091b58e  8b45f8               mov eax, dword ptr [ebp - 8]
// 0091b591  83c00c               add eax, 0xc
// 0091b594  8945f8               mov dword ptr [ebp - 8], eax
// 0091b597  8b4df8               mov ecx, dword ptr [ebp - 8]
// 0091b59a  3b4df0               cmp ecx, dword ptr [ebp - 0x10]
// 0091b59d  7402                 je 0x91b5a1
// 0091b59f  ebed                 jmp 0x91b58e
// 0091b5a1  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 0091b5a4  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0091b5a7  8b4a14               mov ecx, dword ptr [edx + 0x14]
// 0091b5aa  2b480c               sub ecx, dword ptr [eax + 0xc]
// 0091b5ad  8bc1                 mov eax, ecx
// 0091b5af  99                   cdq 
// 0091b5b0  b90c000000           mov ecx, 0xc
// 0091b5b5  f7f9                 idiv ecx
// 0091b5b7  8945e0               mov dword ptr [ebp - 0x20], eax
// 0091b5ba  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 0091b5bd  8b420c               mov eax, dword ptr [edx + 0xc]
// 0091b5c0  8945e4               mov dword ptr [ebp - 0x1c], eax
// 0091b5c3  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 0091b5c6  51                   push ecx
// 0091b5c7  e8cec3e8ff           call 0x7a799a
// 0091b5cc  83c404               add esp, 4
// 0091b5cf  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 0091b5d2  c7420c00000000       mov dword ptr [edx + 0xc], 0
// 0091b5d9  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0091b5dc  c7401000000000       mov dword ptr [eax + 0x10], 0
// 0091b5e3  8b4ddc               mov ecx, dword ptr [ebp - 0x24]
// 0091b5e6  c7411400000000       mov dword ptr [ecx + 0x14], 0
// 0091b5ed  8be5                 mov esp, ebp
// 0091b5ef  5d                   pop ebp
// 0091b5f0  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Tidy@?$vector@VSortedVertex@?$ConvexHull2@M@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
