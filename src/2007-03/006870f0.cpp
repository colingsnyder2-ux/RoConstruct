// from server: 100% by auto
// roc 2007-03 006870f0  unit: seg_00680000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006870f0
//
// 006870f0  56                   push esi
// 006870f1  8bf1                 mov esi, ecx
// 006870f3  e87679f9ff           call 0x61ea6e
// 006870f8  33c0                 xor eax, eax
// 006870fa  c706f4ea7c00         mov dword ptr [esi], 0x7ceaf4
// 00687100  89465c               mov dword ptr [esi + 0x5c], eax
// 00687103  c7465890377900       mov dword ptr [esi + 0x58], 0x793790
// 0068710a  894654               mov dword ptr [esi + 0x54], eax
// 0068710d  8bc6                 mov eax, esi
// 0068710f  5e                   pop esi
// 00687110  c3                   ret 
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ??0CXTPPropertyGridToolTip@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
