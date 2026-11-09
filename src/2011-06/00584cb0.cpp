// from server: 100% by auto
// roc 2011-06 00584cb0  unit: RBX::CRenderSettings  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00584cb0
//
// 00584cb0  55                   push ebp
// 00584cb1  8bec                 mov ebp, esp
// 00584cb3  83ec20               sub esp, 0x20
// 00584cb6  894de0               mov dword ptr [ebp - 0x20], ecx
// 00584cb9  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 00584cbc  83780400             cmp dword ptr [eax + 4], 0
// 00584cc0  744b                 je 0x584d0d
// 00584cc2  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 00584cc5  8b5108               mov edx, dword ptr [ecx + 8]
// 00584cc8  8955ec               mov dword ptr [ebp - 0x14], edx
// 00584ccb  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 00584cce  8b4804               mov ecx, dword ptr [eax + 4]
// 00584cd1  894df0               mov dword ptr [ebp - 0x10], ecx
// 00584cd4  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00584cd7  8955f4               mov dword ptr [ebp - 0xc], edx
// 00584cda  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 00584cdd  8945f8               mov dword ptr [ebp - 8], eax
// 00584ce0  8a4dfe               mov cl, byte ptr [ebp - 2]
// 00584ce3  884dff               mov byte ptr [ebp - 1], cl
// 00584ce6  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 00584ce9  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 00584cec  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 00584cef  2b4804               sub ecx, dword ptr [eax + 4]
// 00584cf2  c1f902               sar ecx, 2
// 00584cf5  894de4               mov dword ptr [ebp - 0x1c], ecx
// 00584cf8  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 00584cfb  8b4204               mov eax, dword ptr [edx + 4]
// 00584cfe  8945e8               mov dword ptr [ebp - 0x18], eax
// 00584d01  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 00584d04  51                   push ecx
// 00584d05  e84e532800           call 0x80a058
// 00584d0a  83c404               add esp, 4
// 00584d0d  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 00584d10  c7420400000000       mov dword ptr [edx + 4], 0
// 00584d17  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 00584d1a  c7400800000000       mov dword ptr [eax + 8], 0
// 00584d21  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 00584d24  c7410c00000000       mov dword ptr [ecx + 0xc], 0
// 00584d2b  8be5                 mov esp, ebp
// 00584d2d  5d                   pop ebp
// 00584d2e  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Tidy@?$vector@HV?$allocator@H@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
