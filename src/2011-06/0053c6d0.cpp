// from server: 100% by auto
// roc 2011-06 0053c6d0  unit: G3D::ReferenceCountedObject  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053c6d0
//
// 0053c6d0  8b442404             mov eax, dword ptr [esp + 4]
// 0053c6d4  014158               add dword ptr [ecx + 0x58], eax
// 0053c6d7  8b542408             mov edx, dword ptr [esp + 8]
// 0053c6db  11515c               adc dword ptr [ecx + 0x5c], edx
// 0053c6de  8b5158               mov edx, dword ptr [ecx + 0x58]
// 0053c6e1  8b415c               mov eax, dword ptr [ecx + 0x5c]
// 0053c6e4  7812                 js 0x53c6f8
// 0053c6e6  7f04                 jg 0x53c6ec
// 0053c6e8  85d2                 test edx, edx
// 0053c6ea  720c                 jb 0x53c6f8
// 0053c6ec  3b414c               cmp eax, dword ptr [ecx + 0x4c]
// 0053c6ef  7c1e                 jl 0x53c70f
// 0053c6f1  7f05                 jg 0x53c6f8
// 0053c6f3  3b5148               cmp edx, dword ptr [ecx + 0x48]
// 0053c6f6  7617                 jbe 0x53c70f
// 0053c6f8  56                   push esi
// 0053c6f9  8b7138               mov esi, dword ptr [ecx + 0x38]
// 0053c6fc  03f2                 add esi, edx
// 0053c6fe  8b513c               mov edx, dword ptr [ecx + 0x3c]
// 0053c701  6a00                 push 0
// 0053c703  6a00                 push 0
// 0053c705  13d0                 adc edx, eax
// 0053c707  52                   push edx
// 0053c708  56                   push esi
// 0053c709  e8626e0000           call 0x543570
// 0053c70e  5e                   pop esi
// 0053c70f  c20800               ret 8
// library rbx2016-g3d/GImage.cpp (function ?skip@BinaryInput@G3D@@QAEX_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
