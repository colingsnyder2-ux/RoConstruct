// from server: 100% by auto
// roc 2009-06 0071bb60  unit: CXTPControlComboBoxList  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071bb60
//
// 0071bb60  56                   push esi
// 0071bb61  8bf1                 mov esi, ecx
// 0071bb63  e8b8d7ffff           call 0x719320
// 0071bb68  33c0                 xor eax, eax
// 0071bb6a  894654               mov dword ptr [esi + 0x54], eax
// 0071bb6d  894658               mov dword ptr [esi + 0x58], eax
// 0071bb70  89465c               mov dword ptr [esi + 0x5c], eax
// 0071bb73  c706fc1b8f00         mov dword ptr [esi], 0x8f1bfc
// 0071bb79  8bc6                 mov eax, esi
// 0071bb7b  5e                   pop esi
// 0071bb7c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ??0CXTPCommandBarEditCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
