// from server: 100% by auto
// roc 2009-06 00761370  unit: ATL::CRegObject  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761370
//
// 00761370  56                   push esi
// 00761371  8bf1                 mov esi, ecx
// 00761373  8b4604               mov eax, dword ptr [esi + 4]
// 00761376  57                   push edi
// 00761377  85c0                 test eax, eax
// 00761379  741d                 je 0x761398
// 0076137b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0076137f  6a00                 push 0
// 00761381  51                   push ecx
// 00761382  ffd0                 call eax
// 00761384  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00761388  50                   push eax
// 00761389  57                   push edi
// 0076138a  8bce                 mov ecx, esi
// 0076138c  e86fffffff           call 0x761300
// 00761391  8bc7                 mov eax, edi
// 00761393  5f                   pop edi
// 00761394  5e                   pop esi
// 00761395  c20800               ret 8
// 00761398  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0076139c  33c0                 xor eax, eax
// 0076139e  50                   push eax
// 0076139f  57                   push edi
// 007613a0  8bce                 mov ecx, esi
// 007613a2  e859ffffff           call 0x761300
// 007613a7  8bc7                 mov eax, edi
// 007613a9  5f                   pop edi
// 007613aa  5e                   pop esi
// 007613ab  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
