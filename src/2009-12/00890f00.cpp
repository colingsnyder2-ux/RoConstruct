// from server: 100% by auto
// roc 2009-12 00890f00  unit: CXTPDockBar  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00890f00
//
// 00890f00  8b442404             mov eax, dword ptr [esp + 4]
// 00890f04  56                   push esi
// 00890f05  57                   push edi
// 00890f06  50                   push eax
// 00890f07  8bf1                 mov esi, ecx
// 00890f09  e822550900           call 0x926430
// 00890f0e  8bf8                 mov edi, eax
// 00890f10  85ff                 test edi, edi
// 00890f12  7416                 je 0x890f2a
// 00890f14  8b4e6c               mov ecx, dword ptr [esi + 0x6c]
// 00890f17  e8c437f8ff           call 0x8146e0
// 00890f1c  8b10                 mov edx, dword ptr [eax]
// 00890f1e  56                   push esi
// 00890f1f  8bc8                 mov ecx, eax
// 00890f21  8b82a4000000         mov eax, dword ptr [edx + 0xa4]
// 00890f27  57                   push edi
// 00890f28  ffd0                 call eax
// 00890f2a  5f                   pop edi
// 00890f2b  b801000000           mov eax, 1
// 00890f30  5e                   pop esi
// 00890f31  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?OnPrintClient@CXTPDockBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
