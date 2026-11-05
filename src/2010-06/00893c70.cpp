// from server: 100% by auto
// roc 2010-06 00893c70  unit: CXTPRichRender  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00893c70
//
// 00893c70  83792400             cmp dword ptr [ecx + 0x24], 0
// 00893c74  7431                 je 0x893ca7
// 00893c76  8b442404             mov eax, dword ptr [esp + 4]
// 00893c7a  85c0                 test eax, eax
// 00893c7c  7403                 je 0x893c81
// 00893c7e  8b4004               mov eax, dword ptr [eax + 4]
// 00893c81  56                   push esi
// 00893c82  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00893c86  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 00893c89  8b11                 mov edx, dword ptr [ecx]
// 00893c8b  6a00                 push 0
// 00893c8d  6a00                 push 0
// 00893c8f  6a00                 push 0
// 00893c91  6a00                 push 0
// 00893c93  6a00                 push 0
// 00893c95  56                   push esi
// 00893c96  6a00                 push 0
// 00893c98  50                   push eax
// 00893c99  8b4210               mov eax, dword ptr [edx + 0x10]
// 00893c9c  6a00                 push 0
// 00893c9e  6a00                 push 0
// 00893ca0  6a00                 push 0
// 00893ca2  6a01                 push 1
// 00893ca4  ffd0                 call eax
// 00893ca6  5e                   pop esi
// 00893ca7  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPRichRender.cpp (function ?DrawTextA@CXTPRichRender@@QAEXPAVCDC@@PBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPRichRender.cpp
