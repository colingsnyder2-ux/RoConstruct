// from server: 100% by auto
// roc 2009-06 007b2540  unit: CXTPDockBar  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b2540
//
// 007b2540  8b442404             mov eax, dword ptr [esp + 4]
// 007b2544  56                   push esi
// 007b2545  57                   push edi
// 007b2546  50                   push eax
// 007b2547  8bf1                 mov esi, ecx
// 007b2549  e8be990900           call 0x84bf0c
// 007b254e  8bf8                 mov edi, eax
// 007b2550  85ff                 test edi, edi
// 007b2552  7416                 je 0x7b256a
// 007b2554  8b4e6c               mov ecx, dword ptr [esi + 0x6c]
// 007b2557  e8a474f7ff           call 0x729a00
// 007b255c  8b10                 mov edx, dword ptr [eax]
// 007b255e  56                   push esi
// 007b255f  8bc8                 mov ecx, eax
// 007b2561  8b82a4000000         mov eax, dword ptr [edx + 0xa4]
// 007b2567  57                   push edi
// 007b2568  ffd0                 call eax
// 007b256a  5f                   pop edi
// 007b256b  b801000000           mov eax, 1
// 007b2570  5e                   pop esi
// 007b2571  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPDockBar.cpp (function ?OnPrintClient@CXTPDockBar@@IAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockBar.cpp
