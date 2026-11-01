// from server: 100% by auto
// roc 2009-12 0083c2d0  unit: CXTPAccessible  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083c2d0
//
// 0083c2d0  56                   push esi
// 0083c2d1  8bf1                 mov esi, ecx
// 0083c2d3  8b4608               mov eax, dword ptr [esi + 8]
// 0083c2d6  57                   push edi
// 0083c2d7  85c0                 test eax, eax
// 0083c2d9  741d                 je 0x83c2f8
// 0083c2db  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0083c2df  6a00                 push 0
// 0083c2e1  51                   push ecx
// 0083c2e2  ffd0                 call eax
// 0083c2e4  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083c2e8  50                   push eax
// 0083c2e9  57                   push edi
// 0083c2ea  8bce                 mov ecx, esi
// 0083c2ec  e87ffdffff           call 0x83c070
// 0083c2f1  8bc7                 mov eax, edi
// 0083c2f3  5f                   pop edi
// 0083c2f4  5e                   pop esi
// 0083c2f5  c20800               ret 8
// 0083c2f8  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083c2fc  33c0                 xor eax, eax
// 0083c2fe  50                   push eax
// 0083c2ff  57                   push edi
// 0083c300  8bce                 mov ecx, esi
// 0083c302  e869fdffff           call 0x83c070
// 0083c307  8bc7                 mov eax, edi
// 0083c309  5f                   pop edi
// 0083c30a  5e                   pop esi
// 0083c30b  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
