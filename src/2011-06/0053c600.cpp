// from server: 100% by auto
// roc 2011-06 0053c600  unit: G3D::ReferenceCountedObject  size: 73 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053c600
//
// 0053c600  8b442404             mov eax, dword ptr [esp + 4]
// 0053c604  8b542408             mov edx, dword ptr [esp + 8]
// 0053c608  56                   push esi
// 0053c609  8b7138               mov esi, dword ptr [ecx + 0x38]
// 0053c60c  2bc6                 sub eax, esi
// 0053c60e  57                   push edi
// 0053c60f  8b793c               mov edi, dword ptr [ecx + 0x3c]
// 0053c612  1bd7                 sbb edx, edi
// 0053c614  89515c               mov dword ptr [ecx + 0x5c], edx
// 0053c617  894158               mov dword ptr [ecx + 0x58], eax
// 0053c61a  8bd0                 mov edx, eax
// 0053c61c  8b415c               mov eax, dword ptr [ecx + 0x5c]
// 0053c61f  85c0                 test eax, eax
// 0053c621  7c12                 jl 0x53c635
// 0053c623  7f04                 jg 0x53c629
// 0053c625  85d2                 test edx, edx
// 0053c627  720c                 jb 0x53c635
// 0053c629  3b414c               cmp eax, dword ptr [ecx + 0x4c]
// 0053c62c  7c16                 jl 0x53c644
// 0053c62e  7f05                 jg 0x53c635
// 0053c630  3b5148               cmp edx, dword ptr [ecx + 0x48]
// 0053c633  760f                 jbe 0x53c644
// 0053c635  6a00                 push 0
// 0053c637  03d6                 add edx, esi
// 0053c639  6a00                 push 0
// 0053c63b  13c7                 adc eax, edi
// 0053c63d  50                   push eax
// 0053c63e  52                   push edx
// 0053c63f  e82c6f0000           call 0x543570
// 0053c644  5f                   pop edi
// 0053c645  5e                   pop esi
// 0053c646  c20800               ret 8
// library rbx2016-g3d/GImage.cpp (function ?setPosition@BinaryInput@G3D@@QAEX_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
