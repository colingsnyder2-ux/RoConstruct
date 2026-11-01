// from server: 100% by auto
// roc 2007-03 006f2170  unit: seg_006f0000  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006f2170
//
// 006f2170  83792400             cmp dword ptr [ecx + 0x24], 0
// 006f2174  7431                 je 0x6f21a7
// 006f2176  8b442404             mov eax, dword ptr [esp + 4]
// 006f217a  85c0                 test eax, eax
// 006f217c  7403                 je 0x6f2181
// 006f217e  8b4004               mov eax, dword ptr [eax + 4]
// 006f2181  56                   push esi
// 006f2182  8b74240c             mov esi, dword ptr [esp + 0xc]
// 006f2186  8b4924               mov ecx, dword ptr [ecx + 0x24]
// 006f2189  8b11                 mov edx, dword ptr [ecx]
// 006f218b  6a00                 push 0
// 006f218d  6a00                 push 0
// 006f218f  6a00                 push 0
// 006f2191  6a00                 push 0
// 006f2193  6a00                 push 0
// 006f2195  56                   push esi
// 006f2196  6a00                 push 0
// 006f2198  50                   push eax
// 006f2199  8b4210               mov eax, dword ptr [edx + 0x10]
// 006f219c  6a00                 push 0
// 006f219e  6a00                 push 0
// 006f21a0  6a00                 push 0
// 006f21a2  6a01                 push 1
// 006f21a4  ffd0                 call eax
// 006f21a6  5e                   pop esi
// 006f21a7  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?DrawTextA@CXTPRichRender@@QAEXPAVCDC@@PBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
