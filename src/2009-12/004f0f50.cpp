// from server: 100% by auto
// roc 2009-12 004f0f50  unit: seg_004f0000  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004f0f50
//
// 004f0f50  55                   push ebp
// 004f0f51  8bec                 mov ebp, esp
// 004f0f53  83ec24               sub esp, 0x24
// 004f0f56  894ddc               mov dword ptr [ebp - 0x24], ecx
// 004f0f59  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 004f0f5c  83780c00             cmp dword ptr [eax + 0xc], 0
// 004f0f60  746d                 je 0x4f0fcf
// 004f0f62  8b4ddc               mov ecx, dword ptr [ebp - 0x24]
// 004f0f65  8b5110               mov edx, dword ptr [ecx + 0x10]
// 004f0f68  8955e8               mov dword ptr [ebp - 0x18], edx
// 004f0f6b  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 004f0f6e  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004f0f71  894dec               mov dword ptr [ebp - 0x14], ecx
// 004f0f74  8b55e8               mov edx, dword ptr [ebp - 0x18]
// 004f0f77  8955f0               mov dword ptr [ebp - 0x10], edx
// 004f0f7a  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004f0f7d  8945f4               mov dword ptr [ebp - 0xc], eax
// 004f0f80  8a4dfe               mov cl, byte ptr [ebp - 2]
// 004f0f83  884dff               mov byte ptr [ebp - 1], cl
// 004f0f86  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 004f0f89  8955f8               mov dword ptr [ebp - 8], edx
// 004f0f8c  eb09                 jmp 0x4f0f97
// 004f0f8e  8b45f8               mov eax, dword ptr [ebp - 8]
// 004f0f91  83c00c               add eax, 0xc
// 004f0f94  8945f8               mov dword ptr [ebp - 8], eax
// 004f0f97  8b4df8               mov ecx, dword ptr [ebp - 8]
// 004f0f9a  3b4df0               cmp ecx, dword ptr [ebp - 0x10]
// 004f0f9d  7402                 je 0x4f0fa1
// 004f0f9f  ebed                 jmp 0x4f0f8e
// 004f0fa1  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 004f0fa4  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 004f0fa7  8b4a14               mov ecx, dword ptr [edx + 0x14]
// 004f0faa  2b480c               sub ecx, dword ptr [eax + 0xc]
// 004f0fad  8bc1                 mov eax, ecx
// 004f0faf  99                   cdq 
// 004f0fb0  b90c000000           mov ecx, 0xc
// 004f0fb5  f7f9                 idiv ecx
// 004f0fb7  8945e0               mov dword ptr [ebp - 0x20], eax
// 004f0fba  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 004f0fbd  8b420c               mov eax, dword ptr [edx + 0xc]
// 004f0fc0  8945e4               mov dword ptr [ebp - 0x1c], eax
// 004f0fc3  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 004f0fc6  51                   push ecx
// 004f0fc7  e88e283000           call 0x7f385a
// 004f0fcc  83c404               add esp, 4
// 004f0fcf  8b55dc               mov edx, dword ptr [ebp - 0x24]
// 004f0fd2  c7420c00000000       mov dword ptr [edx + 0xc], 0
// 004f0fd9  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 004f0fdc  c7401000000000       mov dword ptr [eax + 0x10], 0
// 004f0fe3  8b4ddc               mov ecx, dword ptr [ebp - 0x24]
// 004f0fe6  c7411400000000       mov dword ptr [ecx + 0x14], 0
// 004f0fed  8be5                 mov esp, ebp
// 004f0fef  5d                   pop ebp
// 004f0ff0  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Tidy@?$vector@VSortedVertex@?$ConvexHull2@M@Wml@@V?$allocator@VSortedVertex@?$ConvexHull2@M@Wml@@@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
