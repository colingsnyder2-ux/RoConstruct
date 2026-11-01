// from server: 100% by auto
// roc 2009-12 008dfa00  unit: CXTPRichRender  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008dfa00
//
// 008dfa00  83792400             cmp dword ptr [ecx + 0x24], 0
// 008dfa04  7431                 je 0x8dfa37
// 008dfa06  8b442404             mov eax, dword ptr [esp + 4]
// 008dfa0a  85c0                 test eax, eax
// 008dfa0c  7403                 je 0x8dfa11
// 008dfa0e  8b4004               mov eax, dword ptr [eax + 4]
// 008dfa11  56                   push esi
// 008dfa12  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008dfa16  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 008dfa19  8b11                 mov edx, dword ptr [ecx]
// 008dfa1b  6a00                 push 0
// 008dfa1d  6a00                 push 0
// 008dfa1f  6a00                 push 0
// 008dfa21  6a00                 push 0
// 008dfa23  6a00                 push 0
// 008dfa25  56                   push esi
// 008dfa26  6a00                 push 0
// 008dfa28  50                   push eax
// 008dfa29  8b4210               mov eax, dword ptr [edx + 0x10]
// 008dfa2c  6a00                 push 0
// 008dfa2e  6a00                 push 0
// 008dfa30  6a00                 push 0
// 008dfa32  6a01                 push 1
// 008dfa34  ffd0                 call eax
// 008dfa36  5e                   pop esi
// 008dfa37  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?DrawTextA@CXTPRichRender@@QAEXPAVCDC@@PBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
