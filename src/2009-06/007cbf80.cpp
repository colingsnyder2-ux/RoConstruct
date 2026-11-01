// from server: 100% by auto
// roc 2009-06 007cbf80  unit: CXTPReportNavigator  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cbf80
//
// 007cbf80  56                   push esi
// 007cbf81  8bf1                 mov esi, ecx
// 007cbf83  e898d3f4ff           call 0x719320
// 007cbf88  33c0                 xor eax, eax
// 007cbf8a  894654               mov dword ptr [esi + 0x54], eax
// 007cbf8d  894658               mov dword ptr [esi + 0x58], eax
// 007cbf90  89465c               mov dword ptr [esi + 0x5c], eax
// 007cbf93  c706045b9000         mov dword ptr [esi], 0x905b04
// 007cbf99  8bc6                 mov eax, esi
// 007cbf9b  5e                   pop esi
// 007cbf9c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ??0CXTPCommandBarEditCtrl@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
