// from server: 100% by auto
// roc 2010-06 00845100  unit: CXTPDockBar  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00845100
//
// 00845100  8b442404             mov eax, dword ptr [esp + 4]
// 00845104  56                   push esi
// 00845105  57                   push edi
// 00845106  50                   push eax
// 00845107  8bf1                 mov esi, ecx
// 00845109  e85e7c1300           call 0x97cd6c
// 0084510e  8bf8                 mov edi, eax
// 00845110  85ff                 test edi, edi
// 00845112  7416                 je 0x84512a
// 00845114  8b4e6c               mov ecx, dword ptr [esi + 0x6c]
// 00845117  e8a436f8ff           call 0x7c87c0
// 0084511c  8b10                 mov edx, dword ptr [eax]
// 0084511e  56                   push esi
// 0084511f  8bc8                 mov ecx, eax
// 00845121  8b82a4000000         mov eax, dword ptr [edx + 0xa4]
// 00845127  57                   push edi
// 00845128  ffd0                 call eax
// 0084512a  5f                   pop edi
// 0084512b  b801000000           mov eax, 1
// 00845130  5e                   pop esi
// 00845131  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPDockBar.cpp (function ?OnPrintClient@CXTPDockBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockBar.cpp
