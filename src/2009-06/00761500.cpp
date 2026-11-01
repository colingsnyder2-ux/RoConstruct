// from server: 100% by auto
// roc 2009-06 00761500  unit: ATL::CRegObject  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00761500
//
// 00761500  56                   push esi
// 00761501  8bf1                 mov esi, ecx
// 00761503  8b4608               mov eax, dword ptr [esi + 8]
// 00761506  57                   push edi
// 00761507  85c0                 test eax, eax
// 00761509  741d                 je 0x761528
// 0076150b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0076150f  6a00                 push 0
// 00761511  51                   push ecx
// 00761512  ffd0                 call eax
// 00761514  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00761518  50                   push eax
// 00761519  57                   push edi
// 0076151a  8bce                 mov ecx, esi
// 0076151c  e87ffdffff           call 0x7612a0
// 00761521  8bc7                 mov eax, edi
// 00761523  5f                   pop edi
// 00761524  5e                   pop esi
// 00761525  c20800               ret 8
// 00761528  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0076152c  33c0                 xor eax, eax
// 0076152e  50                   push eax
// 0076152f  57                   push edi
// 00761530  8bce                 mov ecx, esi
// 00761532  e869fdffff           call 0x7612a0
// 00761537  8bc7                 mov eax, edi
// 00761539  5f                   pop edi
// 0076153a  5e                   pop esi
// 0076153b  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
