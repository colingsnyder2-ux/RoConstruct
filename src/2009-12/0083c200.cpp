// from server: 100% by auto
// roc 2009-12 0083c200  unit: CXTPAccessible  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083c200
//
// 0083c200  56                   push esi
// 0083c201  8bf1                 mov esi, ecx
// 0083c203  8b4608               mov eax, dword ptr [esi + 8]
// 0083c206  57                   push edi
// 0083c207  85c0                 test eax, eax
// 0083c209  741d                 je 0x83c228
// 0083c20b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0083c20f  6a00                 push 0
// 0083c211  51                   push ecx
// 0083c212  ffd0                 call eax
// 0083c214  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083c218  50                   push eax
// 0083c219  57                   push edi
// 0083c21a  8bce                 mov ecx, esi
// 0083c21c  e8affeffff           call 0x83c0d0
// 0083c221  8bc7                 mov eax, edi
// 0083c223  5f                   pop edi
// 0083c224  5e                   pop esi
// 0083c225  c20800               ret 8
// 0083c228  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083c22c  33c0                 xor eax, eax
// 0083c22e  50                   push eax
// 0083c22f  57                   push edi
// 0083c230  8bce                 mov ecx, esi
// 0083c232  e899feffff           call 0x83c0d0
// 0083c237  8bc7                 mov eax, edi
// 0083c239  5f                   pop edi
// 0083c23a  5e                   pop esi
// 0083c23b  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
