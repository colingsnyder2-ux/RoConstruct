// roc 2012-06 00670490  unit: RBX::CRenderSettings  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00670490
//
// 00670490  55                   push ebp
// 00670491  8bec                 mov ebp, esp
// 00670493  83ec20               sub esp, 0x20
// 00670496  894de0               mov dword ptr [ebp - 0x20], ecx
// 00670499  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0067049c  83780400             cmp dword ptr [eax + 4], 0
// 006704a0  744b                 je 0x6704ed
// 006704a2  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 006704a5  8b5108               mov edx, dword ptr [ecx + 8]
// 006704a8  8955ec               mov dword ptr [ebp - 0x14], edx
// 006704ab  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 006704ae  8b4804               mov ecx, dword ptr [eax + 4]
// 006704b1  894df0               mov dword ptr [ebp - 0x10], ecx
// 006704b4  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 006704b7  8955f4               mov dword ptr [ebp - 0xc], edx
// 006704ba  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 006704bd  8945f8               mov dword ptr [ebp - 8], eax
// 006704c0  8a4dfe               mov cl, byte ptr [ebp - 2]
// 006704c3  884dff               mov byte ptr [ebp - 1], cl
// 006704c6  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 006704c9  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 006704cc  8b4a0c               mov ecx, dword ptr [edx + 0xc]
// 006704cf  2b4804               sub ecx, dword ptr [eax + 4]
// 006704d2  c1f902               sar ecx, 2
// 006704d5  894de4               mov dword ptr [ebp - 0x1c], ecx
// 006704d8  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 006704db  8b4204               mov eax, dword ptr [edx + 4]
// 006704de  8945e8               mov dword ptr [ebp - 0x18], eax
// 006704e1  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 006704e4  51                   push ecx
// 006704e5  e82a1c3100           call 0x982114
// 006704ea  83c404               add esp, 4
// 006704ed  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 006704f0  c7420400000000       mov dword ptr [edx + 4], 0
// 006704f7  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 006704fa  c7400800000000       mov dword ptr [eax + 8], 0
// 00670501  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 00670504  c7410c00000000       mov dword ptr [ecx + 0xc], 0
// 0067050b  8be5                 mov esp, ebp
// 0067050d  5d                   pop ebp
// 0067050e  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Tidy@?$vector@HV?$allocator@H@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
