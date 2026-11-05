// from server: 100% by auto
// roc 2011-06 008d0360  unit: PAVCXTPDockingPaneBase::?$CList  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008d0360
//
// 008d0360  51                   push ecx
// 008d0361  8d442408             lea eax, [esp + 8]
// 008d0365  50                   push eax
// 008d0366  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008d036a  8d542404             lea edx, [esp + 4]
// 008d036e  52                   push edx
// 008d036f  50                   push eax
// 008d0370  e89beaf9ff           call 0x86ee10
// 008d0375  85c0                 test eax, eax
// 008d0377  7504                 jne 0x8d037d
// 008d0379  59                   pop ecx
// 008d037a  c20800               ret 8
// 008d037d  8b4804               mov ecx, dword ptr [eax + 4]
// 008d0380  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008d0384  890a                 mov dword ptr [edx], ecx
// 008d0386  b801000000           mov eax, 1
// 008d038b  59                   pop ecx
// 008d038c  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\afxcmdusagecount.cpp (function ?Lookup@?$CMap@IIII@@QBEHIAAI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxcmdusagecount.cpp
