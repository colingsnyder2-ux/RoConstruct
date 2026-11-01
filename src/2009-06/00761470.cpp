// from server: 100% by auto
// roc 2009-06 00761470  unit: ATL::CRegObject  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761470
//
// 00761470  56                   push esi
// 00761471  8bf1                 mov esi, ecx
// 00761473  8b4604               mov eax, dword ptr [esi + 4]
// 00761476  57                   push edi
// 00761477  85c0                 test eax, eax
// 00761479  741d                 je 0x761498
// 0076147b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0076147f  6a00                 push 0
// 00761481  51                   push ecx
// 00761482  ffd0                 call eax
// 00761484  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00761488  50                   push eax
// 00761489  57                   push edi
// 0076148a  8bce                 mov ecx, esi
// 0076148c  e80ffeffff           call 0x7612a0
// 00761491  8bc7                 mov eax, edi
// 00761493  5f                   pop edi
// 00761494  5e                   pop esi
// 00761495  c20800               ret 8
// 00761498  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0076149c  33c0                 xor eax, eax
// 0076149e  50                   push eax
// 0076149f  57                   push edi
// 007614a0  8bce                 mov ecx, esi
// 007614a2  e8f9fdffff           call 0x7612a0
// 007614a7  8bc7                 mov eax, edi
// 007614a9  5f                   pop edi
// 007614aa  5e                   pop esi
// 007614ab  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
