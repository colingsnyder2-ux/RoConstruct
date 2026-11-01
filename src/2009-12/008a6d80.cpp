// from server: 100% by auto
// roc 2009-12 008a6d80  unit: CXTPReportNavigator  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a6d80
//
// 008a6d80  56                   push esi
// 008a6d81  8bf1                 mov esi, ecx
// 008a6d83  e8c0d3f4ff           call 0x7f4148
// 008a6d88  33c0                 xor eax, eax
// 008a6d8a  894654               mov dword ptr [esi + 0x54], eax
// 008a6d8d  894658               mov dword ptr [esi + 0x58], eax
// 008a6d90  89465c               mov dword ptr [esi + 0x5c], eax
// 008a6d93  c7067c5fa000         mov dword ptr [esi], 0xa05f7c
// 008a6d99  8bc6                 mov eax, esi
// 008a6d9b  5e                   pop esi
// 008a6d9c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ??0CXTPCommandBarEditCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
