// from server: 100% by auto
// roc 2009-06 00761430  unit: ATL::CRegObject  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761430
//
// 00761430  56                   push esi
// 00761431  8bf1                 mov esi, ecx
// 00761433  8b4608               mov eax, dword ptr [esi + 8]
// 00761436  57                   push edi
// 00761437  85c0                 test eax, eax
// 00761439  741d                 je 0x761458
// 0076143b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0076143f  6a00                 push 0
// 00761441  51                   push ecx
// 00761442  ffd0                 call eax
// 00761444  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00761448  50                   push eax
// 00761449  57                   push edi
// 0076144a  8bce                 mov ecx, esi
// 0076144c  e8affeffff           call 0x761300
// 00761451  8bc7                 mov eax, edi
// 00761453  5f                   pop edi
// 00761454  5e                   pop esi
// 00761455  c20800               ret 8
// 00761458  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0076145c  33c0                 xor eax, eax
// 0076145e  50                   push eax
// 0076145f  57                   push edi
// 00761460  8bce                 mov ecx, esi
// 00761462  e899feffff           call 0x761300
// 00761467  8bc7                 mov eax, edi
// 00761469  5f                   pop edi
// 0076146a  5e                   pop esi
// 0076146b  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
