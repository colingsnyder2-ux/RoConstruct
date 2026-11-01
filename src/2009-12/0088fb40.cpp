// from server: 100% by auto
// roc 2009-12 0088fb40  unit: CXTPShortcutManager  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088fb40
//
// 0088fb40  8bc1                 mov eax, ecx
// 0088fb42  33c9                 xor ecx, ecx
// 0088fb44  894804               mov dword ptr [eax + 4], ecx
// 0088fb47  c7001438a000         mov dword ptr [eax], 0xa03814
// 0088fb4d  894808               mov dword ptr [eax + 8], ecx
// 0088fb50  c3                   ret 
// library xtp-15.2.1/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ??0CXTPGraphicBitmapPng@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
