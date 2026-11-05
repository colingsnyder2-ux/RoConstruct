// from server: 100% by auto
// roc 2010-06 004a1dc0  unit: seg_004a0000  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004a1dc0
//
// 004a1dc0  55                   push ebp
// 004a1dc1  8bec                 mov ebp, esp
// 004a1dc3  83ec20               sub esp, 0x20
// 004a1dc6  33c0                 xor eax, eax
// 004a1dc8  8845ff               mov byte ptr [ebp - 1], al
// 004a1dcb  8a4dff               mov cl, byte ptr [ebp - 1]
// 004a1dce  884de2               mov byte ptr [ebp - 0x1e], cl
// 004a1dd1  8a55fe               mov dl, byte ptr [ebp - 2]
// 004a1dd4  8855e3               mov byte ptr [ebp - 0x1d], dl
// 004a1dd7  8b4508               mov eax, dword ptr [ebp + 8]
// 004a1dda  8945e4               mov dword ptr [ebp - 0x1c], eax
// 004a1ddd  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004a1de0  8b55e4               mov edx, dword ptr [ebp - 0x1c]
// 004a1de3  8d04ca               lea eax, [edx + ecx*8]
// 004a1de6  8945f8               mov dword ptr [ebp - 8], eax
// 004a1de9  33c9                 xor ecx, ecx
// 004a1deb  884df7               mov byte ptr [ebp - 9], cl
// 004a1dee  8a55f7               mov dl, byte ptr [ebp - 9]
// 004a1df1  8855eb               mov byte ptr [ebp - 0x15], dl
// 004a1df4  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004a1df7  8945ec               mov dword ptr [ebp - 0x14], eax
// 004a1dfa  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 004a1dfd  894df0               mov dword ptr [ebp - 0x10], ecx
// 004a1e00  eb12                 jmp 0x4a1e14
// 004a1e02  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 004a1e05  83ea01               sub edx, 1
// 004a1e08  8955ec               mov dword ptr [ebp - 0x14], edx
// 004a1e0b  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004a1e0e  83c008               add eax, 8
// 004a1e11  8945f0               mov dword ptr [ebp - 0x10], eax
// 004a1e14  837dec00             cmp dword ptr [ebp - 0x14], 0
// 004a1e18  760c                 jbe 0x4a1e26
// 004a1e1a  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 004a1e1d  8b5510               mov edx, dword ptr [ebp + 0x10]
// 004a1e20  dd02                 fld qword ptr [edx]
// 004a1e22  dd19                 fstp qword ptr [ecx]
// 004a1e24  ebdc                 jmp 0x4a1e02
// 004a1e26  8be5                 mov esp, ebp
// 004a1e28  5d                   pop ebp
// 004a1e29  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolyhedron3.cpp (function ??$unchecked_fill_n@PANIN@stdext@@YAXPANIABN@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolyhedron3.cpp
