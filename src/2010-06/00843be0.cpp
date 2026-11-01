// from server: 100% by auto
// roc 2010-06 00843be0  unit: CXTPShortcutManager  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00843be0
//
// 00843be0  8b442404             mov eax, dword ptr [esp + 4]
// 00843be4  8b4854               mov ecx, dword ptr [eax + 0x54]
// 00843be7  8b11                 mov edx, dword ptr [ecx]
// 00843be9  8b442408             mov eax, dword ptr [esp + 8]
// 00843bed  8b523c               mov edx, dword ptr [edx + 0x3c]
// 00843bf0  56                   push esi
// 00843bf1  8b742410             mov esi, dword ptr [esp + 0x10]
// 00843bf5  56                   push esi
// 00843bf6  50                   push eax
// 00843bf7  ffd2                 call edx
// 00843bf9  3bc6                 cmp eax, esi
// 00843bfb  5e                   pop esi
// 00843bfc  740b                 je 0x843c09
// 00843bfe  6a00                 push 0
// 00843c00  6aff                 push -1
// 00843c02  6a0e                 push 0xe
// 00843c04  e8d9991300           call 0x97d5e2
// 00843c09  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ?png_read_data@CCallback@CXTPGraphicBitmapPng@@SAXPAUpng_struct_def@@PAEI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
