// from server: 100% by auto
// roc 2007-03 0062f870  unit: seg_00620000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062f870
//
// 0062f870  56                   push esi
// 0062f871  8b742408             mov esi, dword ptr [esp + 8]
// 0062f875  85f6                 test esi, esi
// 0062f877  7509                 jne 0x62f882
// 0062f879  b857000780           mov eax, 0x80070057
// 0062f87e  5e                   pop esi
// 0062f87f  c20400               ret 4
// 0062f882  8b41e0               mov eax, dword ptr [ecx - 0x20]
// 0062f885  8b908c000000         mov edx, dword ptr [eax + 0x8c]
// 0062f88b  83c1e0               add ecx, -0x20
// 0062f88e  ffd2                 call edx
// 0062f890  f7d8                 neg eax
// 0062f892  1bc0                 sbb eax, eax
// 0062f894  f7d8                 neg eax
// 0062f896  8906                 mov dword ptr [esi], eax
// 0062f898  33c0                 xor eax, eax
// 0062f89a  5e                   pop esi
// 0062f89b  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControl.cpp (function ?GetAccessibleChildCount@CXTPControl@@MAEJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControl.cpp
