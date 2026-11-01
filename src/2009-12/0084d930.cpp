// from server: 100% by auto
// roc 2009-12 0084d930  unit: CXTPPrintingDialog  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084d930
//
// 0084d930  56                   push esi
// 0084d931  8bf1                 mov esi, ecx
// 0084d933  e868900d00           call 0x9269a0
// 0084d938  33c0                 xor eax, eax
// 0084d93a  894664               mov dword ptr [esi + 0x64], eax
// 0084d93d  894668               mov dword ptr [esi + 0x68], eax
// 0084d940  894660               mov dword ptr [esi + 0x60], eax
// 0084d943  89465c               mov dword ptr [esi + 0x5c], eax
// 0084d946  c706acbc9f00         mov dword ptr [esi], 0x9fbcac
// 0084d94c  8bc6                 mov eax, esi
// 0084d94e  5e                   pop esi
// 0084d94f  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ??0CXTPPropertyGridToolBar@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
