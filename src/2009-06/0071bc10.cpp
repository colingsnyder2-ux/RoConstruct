// from server: 100% by auto
// roc 2009-06 0071bc10  unit: CXTPEdit  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071bc10
//
// 0071bc10  8b442404             mov eax, dword ptr [esp + 4]
// 0071bc14  3d25e10000           cmp eax, 0xe125
// 0071bc19  740e                 je 0x71bc29
// 0071bc1b  3d23e10000           cmp eax, 0xe123
// 0071bc20  7407                 je 0x71bc29
// 0071bc22  3d22e10000           cmp eax, 0xe122
// 0071bc27  7526                 jne 0x71bc4f
// 0071bc29  837c2408ff           cmp dword ptr [esp + 8], -1
// 0071bc2e  751f                 jne 0x71bc4f
// 0071bc30  56                   push esi
// 0071bc31  8b742410             mov esi, dword ptr [esp + 0x10]
// 0071bc35  57                   push edi
// 0071bc36  8b3e                 mov edi, dword ptr [esi]
// 0071bc38  50                   push eax
// 0071bc39  e842ffffff           call 0x71bb80
// 0071bc3e  50                   push eax
// 0071bc3f  8b07                 mov eax, dword ptr [edi]
// 0071bc41  8bce                 mov ecx, esi
// 0071bc43  ffd0                 call eax
// 0071bc45  5f                   pop edi
// 0071bc46  b801000000           mov eax, 1
// 0071bc4b  5e                   pop esi
// 0071bc4c  c21000               ret 0x10
// 0071bc4f  33c0                 xor eax, eax
// 0071bc51  c21000               ret 0x10
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnCmdMsg@CXTPCommandBarEditCtrl@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
