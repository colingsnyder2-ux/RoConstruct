// from server: 100% by auto
// roc 2010-06 00843d40  unit: CXTPShortcutManager  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00843d40
//
// 00843d40  8bc1                 mov eax, ecx
// 00843d42  33c9                 xor ecx, ecx
// 00843d44  894804               mov dword ptr [eax + 4], ecx
// 00843d47  c700f47aa600         mov dword ptr [eax], 0xa67af4
// 00843d4d  894808               mov dword ptr [eax + 8], ecx
// 00843d50  c3                   ret 
// library xtp-13.2.1/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ??0CXTPGraphicBitmapPng@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
