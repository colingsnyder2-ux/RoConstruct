// from server: 100% by auto
// roc 2010-06 0049f450  unit: seg_00490000  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0049f450
//
// 0049f450  55                   push ebp
// 0049f451  8bec                 mov ebp, esp
// 0049f453  83ec20               sub esp, 0x20
// 0049f456  894de0               mov dword ptr [ebp - 0x20], ecx
// 0049f459  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0049f45c  83780c00             cmp dword ptr [eax + 0xc], 0
// 0049f460  744b                 je 0x49f4ad
// 0049f462  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 0049f465  8b5110               mov edx, dword ptr [ecx + 0x10]
// 0049f468  8955ec               mov dword ptr [ebp - 0x14], edx
// 0049f46b  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0049f46e  8b480c               mov ecx, dword ptr [eax + 0xc]
// 0049f471  894df0               mov dword ptr [ebp - 0x10], ecx
// 0049f474  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 0049f477  8955f4               mov dword ptr [ebp - 0xc], edx
// 0049f47a  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 0049f47d  8945f8               mov dword ptr [ebp - 8], eax
// 0049f480  8a4dfe               mov cl, byte ptr [ebp - 2]
// 0049f483  884dff               mov byte ptr [ebp - 1], cl
// 0049f486  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0049f489  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0049f48c  8b4a14               mov ecx, dword ptr [edx + 0x14]
// 0049f48f  2b480c               sub ecx, dword ptr [eax + 0xc]
// 0049f492  c1f903               sar ecx, 3
// 0049f495  894de4               mov dword ptr [ebp - 0x1c], ecx
// 0049f498  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0049f49b  8b420c               mov eax, dword ptr [edx + 0xc]
// 0049f49e  8945e8               mov dword ptr [ebp - 0x18], eax
// 0049f4a1  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 0049f4a4  51                   push ecx
// 0049f4a5  e8f0843000           call 0x7a799a
// 0049f4aa  83c404               add esp, 4
// 0049f4ad  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0049f4b0  c7420c00000000       mov dword ptr [edx + 0xc], 0
// 0049f4b7  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0049f4ba  c7401000000000       mov dword ptr [eax + 0x10], 0
// 0049f4c1  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 0049f4c4  c7411400000000       mov dword ptr [ecx + 0x14], 0
// 0049f4cb  8be5                 mov esp, ebp
// 0049f4cd  5d                   pop ebp
// 0049f4ce  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ?_Tidy@?$vector@NV?$allocator@N@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
