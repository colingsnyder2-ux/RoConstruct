// from server: 100% by auto
// roc 2012-06 006285c0  unit: G3D::ReferenceCountedObject  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006285c0
//
// 006285c0  8b442404             mov eax, dword ptr [esp + 4]
// 006285c4  014158               add dword ptr [ecx + 0x58], eax
// 006285c7  8b542408             mov edx, dword ptr [esp + 8]
// 006285cb  11515c               adc dword ptr [ecx + 0x5c], edx
// 006285ce  8b5158               mov edx, dword ptr [ecx + 0x58]
// 006285d1  8b415c               mov eax, dword ptr [ecx + 0x5c]
// 006285d4  7812                 js 0x6285e8
// 006285d6  7f04                 jg 0x6285dc
// 006285d8  85d2                 test edx, edx
// 006285da  720c                 jb 0x6285e8
// 006285dc  3b414c               cmp eax, dword ptr [ecx + 0x4c]
// 006285df  7c1e                 jl 0x6285ff
// 006285e1  7f05                 jg 0x6285e8
// 006285e3  3b5148               cmp edx, dword ptr [ecx + 0x48]
// 006285e6  7617                 jbe 0x6285ff
// 006285e8  56                   push esi
// 006285e9  8b7138               mov esi, dword ptr [ecx + 0x38]
// 006285ec  03f2                 add esi, edx
// 006285ee  8b513c               mov edx, dword ptr [ecx + 0x3c]
// 006285f1  6a00                 push 0
// 006285f3  6a00                 push 0
// 006285f5  13d0                 adc edx, eax
// 006285f7  52                   push edx
// 006285f8  56                   push esi
// 006285f9  e8e26d0000           call 0x62f3e0
// 006285fe  5e                   pop esi
// 006285ff  c20800               ret 8
// library rbx2016-g3d/GImage.cpp (function ?skip@BinaryInput@G3D@@QAEX_J@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
