// from server: 100% by auto
// roc 2012-06 0062eb60  unit: G3D::Line  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062eb60
//
// 0062eb60  56                   push esi
// 0062eb61  8bf1                 mov esi, ecx
// 0062eb63  d906                 fld dword ptr [esi]
// 0062eb65  57                   push edi
// 0062eb66  83ec08               sub esp, 8
// 0062eb69  dd1c24               fstp qword ptr [esp]
// 0062eb6c  e8c54f3500           call 0x983b36
// 0062eb71  e83a4a3500           call 0x9835b0
// 0062eb76  d94604               fld dword ptr [esi + 4]
// 0062eb79  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0062eb7d  dd1c24               fstp qword ptr [esp]
// 0062eb80  668907               mov word ptr [edi], ax
// 0062eb83  e8ae4f3500           call 0x983b36
// 0062eb88  e8234a3500           call 0x9835b0
// 0062eb8d  d94608               fld dword ptr [esi + 8]
// 0062eb90  dd1c24               fstp qword ptr [esp]
// 0062eb93  66894702             mov word ptr [edi + 2], ax
// 0062eb97  e89a4f3500           call 0x983b36
// 0062eb9c  83c408               add esp, 8
// 0062eb9f  e80c4a3500           call 0x9835b0
// 0062eba4  66894704             mov word ptr [edi + 4], ax
// 0062eba8  8bc7                 mov eax, edi
// 0062ebaa  5f                   pop edi
// 0062ebab  5e                   pop esi
// 0062ebac  c20400               ret 4
// library rbx2016-g3d/Vector3.cpp (function ?toVector3int16@Vector3@G3D@@QBE?AVVector3int16@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Vector3.cpp
