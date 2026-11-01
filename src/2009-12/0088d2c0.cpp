// from server: 100% by auto
// roc 2009-12 0088d2c0  unit: CXTPControlEditCtrl  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088d2c0
//
// 0088d2c0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0088d2c4  0faf442410           imul eax, dword ptr [esp + 0x10]
// 0088d2c9  8a542418             mov dl, byte ptr [esp + 0x18]
// 0088d2cd  03c0                 add eax, eax
// 0088d2cf  80c9ff               or cl, 0xff
// 0088d2d2  03c0                 add eax, eax
// 0088d2d4  2aca                 sub cl, dl
// 0088d2d6  85c0                 test eax, eax
// 0088d2d8  7e47                 jle 0x88d321
// 0088d2da  53                   push ebx
// 0088d2db  55                   push ebp
// 0088d2dc  0fb6e9               movzx ebp, cl
// 0088d2df  0fb6ca               movzx ecx, dl
// 0088d2e2  56                   push esi
// 0088d2e3  8b742420             mov esi, dword ptr [esp + 0x20]
// 0088d2e7  57                   push edi
// 0088d2e8  894c2428             mov dword ptr [esp + 0x28], ecx
// 0088d2ec  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0088d2f0  8bf8                 mov edi, eax
// 0088d2f2  8b442414             mov eax, dword ptr [esp + 0x14]
// 0088d2f6  eb08                 jmp 0x88d300
// 0088d2f8  8da42400000000       lea esp, [esp]
// 0088d2ff  90                   nop 
// 0088d300  0fb616               movzx edx, byte ptr [esi]
// 0088d303  0fb619               movzx ebx, byte ptr [ecx]
// 0088d306  0faf542428           imul edx, dword ptr [esp + 0x28]
// 0088d30b  0fafdd               imul ebx, ebp
// 0088d30e  03d3                 add edx, ebx
// 0088d310  c1fa08               sar edx, 8
// 0088d313  8810                 mov byte ptr [eax], dl
// 0088d315  40                   inc eax
// 0088d316  41                   inc ecx
// 0088d317  46                   inc esi
// 0088d318  83ef01               sub edi, 1
// 0088d31b  75e3                 jne 0x88d300
// 0088d31d  5f                   pop edi
// 0088d31e  5e                   pop esi
// 0088d31f  5d                   pop ebp
// 0088d320  5b                   pop ebx
// 0088d321  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?AlphaBlendU@CXTPCommandBarAnimation@@IAEXPAE0HH0E@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
