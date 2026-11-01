// from server: 100% by auto
// roc 2007-03 006b41c0  unit: seg_006b0000  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b41c0
//
// 006b41c0  56                   push esi
// 006b41c1  8bf1                 mov esi, ecx
// 006b41c3  57                   push edi
// 006b41c4  33ff                 xor edi, edi
// 006b41c6  8d4e1c               lea ecx, [esi + 0x1c]
// 006b41c9  897e08               mov dword ptr [esi + 8], edi
// 006b41cc  c7460480747800       mov dword ptr [esi + 4], 0x787480
// 006b41d3  e878feffff           call 0x6b4050
// 006b41d8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b41dc  897e0c               mov dword ptr [esi + 0xc], edi
// 006b41df  897e10               mov dword ptr [esi + 0x10], edi
// 006b41e2  897e14               mov dword ptr [esi + 0x14], edi
// 006b41e5  897e18               mov dword ptr [esi + 0x18], edi
// 006b41e8  8906                 mov dword ptr [esi], eax
// 006b41ea  5f                   pop edi
// 006b41eb  8bc6                 mov eax, esi
// 006b41ed  5e                   pop esi
// 006b41ee  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ??0CXTPCommandBarAnimation@@QAE@PAVCXTPCommandBar@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
