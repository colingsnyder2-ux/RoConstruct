// from server: 100% by auto
// roc 2009-12 004ee510  unit: seg_004e0000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ee510
//
// 004ee510  55                   push ebp
// 004ee511  8bec                 mov ebp, esp
// 004ee513  83ec20               sub esp, 0x20
// 004ee516  33c0                 xor eax, eax
// 004ee518  8845ff               mov byte ptr [ebp - 1], al
// 004ee51b  8a4dff               mov cl, byte ptr [ebp - 1]
// 004ee51e  884de2               mov byte ptr [ebp - 0x1e], cl
// 004ee521  8a55fe               mov dl, byte ptr [ebp - 2]
// 004ee524  8855e3               mov byte ptr [ebp - 0x1d], dl
// 004ee527  8b4508               mov eax, dword ptr [ebp + 8]
// 004ee52a  8945e4               mov dword ptr [ebp - 0x1c], eax
// 004ee52d  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004ee530  8b55e4               mov edx, dword ptr [ebp - 0x1c]
// 004ee533  8d04ca               lea eax, [edx + ecx*8]
// 004ee536  8945f8               mov dword ptr [ebp - 8], eax
// 004ee539  33c9                 xor ecx, ecx
// 004ee53b  884df7               mov byte ptr [ebp - 9], cl
// 004ee53e  8a55f7               mov dl, byte ptr [ebp - 9]
// 004ee541  8855eb               mov byte ptr [ebp - 0x15], dl
// 004ee544  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004ee547  8945ec               mov dword ptr [ebp - 0x14], eax
// 004ee54a  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 004ee54d  894df0               mov dword ptr [ebp - 0x10], ecx
// 004ee550  eb12                 jmp 0x4ee564
// 004ee552  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004ee555  83ea01               sub edx, 1
// 004ee558  8955ec               mov dword ptr [ebp - 0x14], edx
// 004ee55b  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004ee55e  83c008               add eax, 8
// 004ee561  8945f0               mov dword ptr [ebp - 0x10], eax
// 004ee564  837dec00             cmp dword ptr [ebp - 0x14], 0
// 004ee568  760c                 jbe 0x4ee576
// 004ee56a  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004ee56d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004ee570  dd02                 fld qword ptr [edx]
// 004ee572  dd19                 fstp qword ptr [ecx]
// 004ee574  ebdc                 jmp 0x4ee552
// 004ee576  8be5                 mov esp, ebp
// 004ee578  5d                   pop ebp
// 004ee579  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ??$unchecked_fill_n@PANIN@stdext@@YAXPANIABN@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
