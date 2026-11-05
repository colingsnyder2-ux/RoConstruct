// from server: 100% by auto
// roc 2010-06 007b4a10  unit: CXTPControlComboBoxList  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4a10
//
// 007b4a10  56                   push esi
// 007b4a11  8bf1                 mov esi, ecx
// 007b4a13  e87038ffff           call 0x7a8288
// 007b4a18  33c0                 xor eax, eax
// 007b4a1a  894654               mov dword ptr [esi + 0x54], eax
// 007b4a1d  894658               mov dword ptr [esi + 0x58], eax
// 007b4a20  89465c               mov dword ptr [esi + 0x5c], eax
// 007b4a23  c7066c68a500         mov dword ptr [esi], 0xa5686c
// 007b4a29  8bc6                 mov eax, esi
// 007b4a2b  5e                   pop esi
// 007b4a2c  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ??0CXTPCommandBarEditCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
