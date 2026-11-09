// from server: 100% by auto
// roc 2009-12 004ebc30  unit: seg_004e0000  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ebc30
//
// 004ebc30  55                   push ebp
// 004ebc31  8bec                 mov ebp, esp
// 004ebc33  83ec20               sub esp, 0x20
// 004ebc36  894de0               mov dword ptr [ebp - 0x20], ecx
// 004ebc39  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 004ebc3c  83780c00             cmp dword ptr [eax + 0xc], 0
// 004ebc40  744b                 je 0x4ebc8d
// 004ebc42  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 004ebc45  8b5110               mov edx, dword ptr [ecx + 0x10]
// 004ebc48  8955ec               mov dword ptr [ebp - 0x14], edx
// 004ebc4b  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 004ebc4e  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004ebc51  894df0               mov dword ptr [ebp - 0x10], ecx
// 004ebc54  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004ebc57  8955f4               mov dword ptr [ebp - 0xc], edx
// 004ebc5a  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004ebc5d  8945f8               mov dword ptr [ebp - 8], eax
// 004ebc60  8a4dfe               mov cl, byte ptr [ebp - 2]
// 004ebc63  884dff               mov byte ptr [ebp - 1], cl
// 004ebc66  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 004ebc69  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 004ebc6c  8b4a14               mov ecx, dword ptr [edx + 0x14]
// 004ebc6f  2b480c               sub ecx, dword ptr [eax + 0xc]
// 004ebc72  c1f903               sar ecx, 3
// 004ebc75  894de4               mov dword ptr [ebp - 0x1c], ecx
// 004ebc78  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 004ebc7b  8b420c               mov eax, dword ptr [edx + 0xc]
// 004ebc7e  8945e8               mov dword ptr [ebp - 0x18], eax
// 004ebc81  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 004ebc84  51                   push ecx
// 004ebc85  e8d07b3000           call 0x7f385a
// 004ebc8a  83c404               add esp, 4
// 004ebc8d  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 004ebc90  c7420c00000000       mov dword ptr [edx + 0xc], 0
// 004ebc97  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 004ebc9a  c7401000000000       mov dword ptr [eax + 0x10], 0
// 004ebca1  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 004ebca4  c7411400000000       mov dword ptr [ecx + 0x14], 0
// 004ebcab  8be5                 mov esp, ebp
// 004ebcad  5d                   pop ebp
// 004ebcae  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ?_Tidy@?$vector@NV?$allocator@N@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
