// from server: 100% by auto
// roc 2007-03 006bfa30  unit: seg_006b0000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006bfa30
//
// 006bfa30  56                   push esi
// 006bfa31  8bf1                 mov esi, ecx
// 006bfa33  e836f0f5ff           call 0x61ea6e
// 006bfa38  33c0                 xor eax, eax
// 006bfa3a  894654               mov dword ptr [esi + 0x54], eax
// 006bfa3d  894658               mov dword ptr [esi + 0x58], eax
// 006bfa40  89465c               mov dword ptr [esi + 0x5c], eax
// 006bfa43  c7064c557d00         mov dword ptr [esi], 0x7d554c
// 006bfa49  8bc6                 mov eax, esi
// 006bfa4b  5e                   pop esi
// 006bfa4c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ??0CXTPCommandBarEditCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
