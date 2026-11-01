// from server: 100% by auto
// roc 2009-12 00923940  unit: seg_00920000  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00923940
//
// 00923940  55                   push ebp
// 00923941  8bec                 mov ebp, esp
// 00923943  83ec20               sub esp, 0x20
// 00923946  894de0               mov dword ptr [ebp - 0x20], ecx
// 00923949  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0092394c  83780c00             cmp dword ptr [eax + 0xc], 0
// 00923950  744b                 je 0x92399d
// 00923952  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 00923955  8b5110               mov edx, dword ptr [ecx + 0x10]
// 00923958  8955ec               mov dword ptr [ebp - 0x14], edx
// 0092395b  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0092395e  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00923961  894df0               mov dword ptr [ebp - 0x10], ecx
// 00923964  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 00923967  8955f4               mov dword ptr [ebp - 0xc], edx
// 0092396a  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 0092396d  8945f8               mov dword ptr [ebp - 8], eax
// 00923970  8a4dfe               mov cl, byte ptr [ebp - 2]
// 00923973  884dff               mov byte ptr [ebp - 1], cl
// 00923976  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 00923979  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0092397c  8b4a14               mov ecx, dword ptr [edx + 0x14]
// 0092397f  2b480c               sub ecx, dword ptr [eax + 0xc]
// 00923982  c1f902               sar ecx, 2
// 00923985  894de4               mov dword ptr [ebp - 0x1c], ecx
// 00923988  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0092398b  8b420c               mov eax, dword ptr [edx + 0xc]
// 0092398e  8945e8               mov dword ptr [ebp - 0x18], eax
// 00923991  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 00923994  51                   push ecx
// 00923995  e8c0feecff           call 0x7f385a
// 0092399a  83c404               add esp, 4
// 0092399d  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 009239a0  c7420c00000000       mov dword ptr [edx + 0xc], 0
// 009239a7  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 009239aa  c7401000000000       mov dword ptr [eax + 0x10], 0
// 009239b1  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 009239b4  c7411400000000       mov dword ptr [ecx + 0x14], 0
// 009239bb  8be5                 mov esp, ebp
// 009239bd  5d                   pop ebp
// 009239be  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Tidy@?$vector@HV?$allocator@H@std@@@std@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
