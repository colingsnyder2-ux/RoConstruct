// from server: 100% by auto
// roc 2011-06 008a0de0  unit: CXTPShortcutManager  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a0de0
//
// 008a0de0  8b442404             mov eax, dword ptr [esp + 4]
// 008a0de4  8b4854               mov ecx, dword ptr [eax + 0x54]
// 008a0de7  8b11                 mov edx, dword ptr [ecx]
// 008a0de9  8b442408             mov eax, dword ptr [esp + 8]
// 008a0ded  8b523c               mov edx, dword ptr [edx + 0x3c]
// 008a0df0  56                   push esi
// 008a0df1  8b742410             mov esi, dword ptr [esp + 0x10]
// 008a0df5  56                   push esi
// 008a0df6  50                   push eax
// 008a0df7  ffd2                 call edx
// 008a0df9  3bc6                 cmp eax, esi
// 008a0dfb  5e                   pop esi
// 008a0dfc  740b                 je 0x8a0e09
// 008a0dfe  6a00                 push 0
// 008a0e00  6aff                 push -1
// 008a0e02  6a0e                 push 0xe
// 008a0e04  e81dbf1200           call 0x9ccd26
// 008a0e09  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ?png_read_data@CCallback@CXTPGraphicBitmapPng@@SAXPAUpng_struct_def@@PAEI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
