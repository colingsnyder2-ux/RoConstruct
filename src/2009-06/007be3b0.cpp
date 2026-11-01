// from server: 100% by auto
// roc 2009-06 007be3b0  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007be3b0
//
// 007be3b0  8bc1                 mov eax, ecx
// 007be3b2  33c9                 xor ecx, ecx
// 007be3b4  894804               mov dword ptr [eax + 4], ecx
// 007be3b7  c700ac4b9000         mov dword ptr [eax], 0x904bac
// 007be3bd  894808               mov dword ptr [eax + 8], ecx
// 007be3c0  c3                   ret 
// library xtp-15.2.1/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ??0CXTPGraphicBitmapPng@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
