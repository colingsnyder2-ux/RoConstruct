// from server: 100% by auto
// roc 2007-03 00693570  unit: seg_00690000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00693570
//
// 00693570  8bc1                 mov eax, ecx
// 00693572  33c9                 xor ecx, ecx
// 00693574  894804               mov dword ptr [eax + 4], ecx
// 00693577  c700500a7d00         mov dword ptr [eax], 0x7d0a50
// 0069357d  894808               mov dword ptr [eax + 8], ecx
// 00693580  c3                   ret 
// library xtp-15.2.1/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ??0CXTPGraphicBitmapPng@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
