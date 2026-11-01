// from server: 100% by auto
// roc 2009-12 00924830  unit: seg_00920000  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00924830
//
// 00924830  55                   push ebp
// 00924831  8bec                 mov ebp, esp
// 00924833  83ec34               sub esp, 0x34
// 00924836  894dcc               mov dword ptr [ebp - 0x34], ecx
// 00924839  8b4508               mov eax, dword ptr [ebp + 8]
// 0092483c  8945d0               mov dword ptr [ebp - 0x30], eax
// 0092483f  33c9                 xor ecx, ecx
// 00924841  884dff               mov byte ptr [ebp - 1], cl
// 00924844  8a55fd               mov dl, byte ptr [ebp - 3]
// 00924847  8855fe               mov byte ptr [ebp - 2], dl
// 0092484a  8a45ff               mov al, byte ptr [ebp - 1]
// 0092484d  8845d7               mov byte ptr [ebp - 0x29], al
// 00924850  8b4dd0               mov ecx, dword ptr [ebp - 0x30]
// 00924853  894dd8               mov dword ptr [ebp - 0x28], ecx
// 00924856  8b5510               mov edx, dword ptr [ebp + 0x10]
// 00924859  52                   push edx
// 0092485a  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0092485d  50                   push eax
// 0092485e  8b4dd8               mov ecx, dword ptr [ebp - 0x28]
// 00924861  51                   push ecx
// 00924862  e8c9170000           call 0x926030
// 00924867  83c40c               add esp, 0xc
// 0092486a  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0092486d  8b4508               mov eax, dword ptr [ebp + 8]
// 00924870  8d0490               lea eax, [eax + edx*4]
// 00924873  8be5                 mov esp, ebp
// 00924875  5d                   pop ebp
// 00924876  c20c00               ret 0xc
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ?_Ufill@?$vector@HV?$allocator@H@std@@@std@@IAEPAHPAHIABH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
