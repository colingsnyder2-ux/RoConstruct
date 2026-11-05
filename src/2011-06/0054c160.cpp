// from server: 100% by auto
// roc 2011-06 0054c160  unit: G3D::_internal::DialogTemplate  size: 77 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0054c160
//
// 0054c160  8b442404             mov eax, dword ptr [esp + 4]
// 0054c164  2b4148               sub eax, dword ptr [ecx + 0x48]
// 0054c167  7917                 jns 0x54c180
// 0054c169  68dc27ba00           push 0xba27dc
// 0054c16e  8d442408             lea eax, [esp + 8]
// 0054c172  50                   push eax
// 0054c173  c744240ca800a800     mov dword ptr [esp + 0xc], 0xa800a8
// 0054c17b  e82cef2b00           call 0x80b0ac
// 0054c180  56                   push esi
// 0054c181  8b7138               mov esi, dword ptr [ecx + 0x38]
// 0054c184  3bc6                 cmp eax, esi
// 0054c186  7d03                 jge 0x54c18b
// 0054c188  894140               mov dword ptr [ecx + 0x40], eax
// 0054c18b  7e1c                 jle 0x54c1a9
// 0054c18d  8b5140               mov edx, dword ptr [ecx + 0x40]
// 0054c190  2bc6                 sub eax, esi
// 0054c192  03d0                 add edx, eax
// 0054c194  3bf2                 cmp esi, edx
// 0054c196  7c02                 jl 0x54c19a
// 0054c198  8bd6                 mov edx, esi
// 0054c19a  3b513c               cmp edx, dword ptr [ecx + 0x3c]
// 0054c19d  895138               mov dword ptr [ecx + 0x38], edx
// 0054c1a0  7e07                 jle 0x54c1a9
// 0054c1a2  56                   push esi
// 0054c1a3  50                   push eax
// 0054c1a4  e8878fffff           call 0x545130
// 0054c1a9  5e                   pop esi
// 0054c1aa  c20400               ret 4
// library rbx2016-g3d/GImage_bmp.cpp (function ?setLength@BinaryOutput@G3D@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage_bmp.cpp
