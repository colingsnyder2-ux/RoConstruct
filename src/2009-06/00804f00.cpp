// from server: 100% by auto
// roc 2009-06 00804f00  unit: CXTPRichRender  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00804f00
//
// 00804f00  83792400             cmp dword ptr [ecx + 0x24], 0
// 00804f04  7431                 je 0x804f37
// 00804f06  8b442404             mov eax, dword ptr [esp + 4]
// 00804f0a  85c0                 test eax, eax
// 00804f0c  7403                 je 0x804f11
// 00804f0e  8b4004               mov eax, dword ptr [eax + 4]
// 00804f11  56                   push esi
// 00804f12  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00804f16  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 00804f19  8b11                 mov edx, dword ptr [ecx]
// 00804f1b  6a00                 push 0
// 00804f1d  6a00                 push 0
// 00804f1f  6a00                 push 0
// 00804f21  6a00                 push 0
// 00804f23  6a00                 push 0
// 00804f25  56                   push esi
// 00804f26  6a00                 push 0
// 00804f28  50                   push eax
// 00804f29  8b4210               mov eax, dword ptr [edx + 0x10]
// 00804f2c  6a00                 push 0
// 00804f2e  6a00                 push 0
// 00804f30  6a00                 push 0
// 00804f32  6a01                 push 1
// 00804f34  ffd0                 call eax
// 00804f36  5e                   pop esi
// 00804f37  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?DrawTextA@CXTPRichRender@@QAEXPAVCDC@@PBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
