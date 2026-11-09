// from server: 100% by auto
// roc 2012-06 00628570  unit: G3D::ReferenceCountedObject  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00628570
//
// 00628570  8b442404             mov eax, dword ptr [esp + 4]
// 00628574  8b542408             mov edx, dword ptr [esp + 8]
// 00628578  56                   push esi
// 00628579  8b7138               mov esi, dword ptr [ecx + 0x38]
// 0062857c  2bc6                 sub eax, esi
// 0062857e  57                   push edi
// 0062857f  8b793c               mov edi, dword ptr [ecx + 0x3c]
// 00628582  1bd7                 sbb edx, edi
// 00628584  89515c               mov dword ptr [ecx + 0x5c], edx
// 00628587  894158               mov dword ptr [ecx + 0x58], eax
// 0062858a  8bd0                 mov edx, eax
// 0062858c  8b415c               mov eax, dword ptr [ecx + 0x5c]
// 0062858f  85c0                 test eax, eax
// 00628591  7c12                 jl 0x6285a5
// 00628593  7f04                 jg 0x628599
// 00628595  85d2                 test edx, edx
// 00628597  720c                 jb 0x6285a5
// 00628599  3b414c               cmp eax, dword ptr [ecx + 0x4c]
// 0062859c  7c16                 jl 0x6285b4
// 0062859e  7f05                 jg 0x6285a5
// 006285a0  3b5148               cmp edx, dword ptr [ecx + 0x48]
// 006285a3  760f                 jbe 0x6285b4
// 006285a5  6a00                 push 0
// 006285a7  03d6                 add edx, esi
// 006285a9  6a00                 push 0
// 006285ab  13c7                 adc eax, edi
// 006285ad  50                   push eax
// 006285ae  52                   push edx
// 006285af  e82c6e0000           call 0x62f3e0
// 006285b4  5f                   pop edi
// 006285b5  5e                   pop esi
// 006285b6  c20800               ret 8
// library rbx2016-g3d/GImage.cpp (function ?setPosition@BinaryInput@G3D@@QAEX_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
