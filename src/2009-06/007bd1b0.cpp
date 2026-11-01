// from server: 100% by auto
// roc 2009-06 007bd1b0  unit: CXTPRibbonBar  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bd1b0
//
// 007bd1b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007bd1b4  0faf442410           imul eax, dword ptr [esp + 0x10]
// 007bd1b9  8a542418             mov dl, byte ptr [esp + 0x18]
// 007bd1bd  03c0                 add eax, eax
// 007bd1bf  80c9ff               or cl, 0xff
// 007bd1c2  03c0                 add eax, eax
// 007bd1c4  2aca                 sub cl, dl
// 007bd1c6  85c0                 test eax, eax
// 007bd1c8  7e47                 jle 0x7bd211
// 007bd1ca  53                   push ebx
// 007bd1cb  55                   push ebp
// 007bd1cc  0fb6e9               movzx ebp, cl
// 007bd1cf  0fb6ca               movzx ecx, dl
// 007bd1d2  56                   push esi
// 007bd1d3  8b742420             mov esi, dword ptr [esp + 0x20]
// 007bd1d7  57                   push edi
// 007bd1d8  894c2428             mov dword ptr [esp + 0x28], ecx
// 007bd1dc  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007bd1e0  8bf8                 mov edi, eax
// 007bd1e2  8b442414             mov eax, dword ptr [esp + 0x14]
// 007bd1e6  eb08                 jmp 0x7bd1f0
// 007bd1e8  8da42400000000       lea esp, [esp]
// 007bd1ef  90                   nop 
// 007bd1f0  0fb616               movzx edx, byte ptr [esi]
// 007bd1f3  0fb619               movzx ebx, byte ptr [ecx]
// 007bd1f6  0faf542428           imul edx, dword ptr [esp + 0x28]
// 007bd1fb  0fafdd               imul ebx, ebp
// 007bd1fe  03d3                 add edx, ebx
// 007bd200  c1fa08               sar edx, 8
// 007bd203  8810                 mov byte ptr [eax], dl
// 007bd205  40                   inc eax
// 007bd206  41                   inc ecx
// 007bd207  46                   inc esi
// 007bd208  83ef01               sub edi, 1
// 007bd20b  75e3                 jne 0x7bd1f0
// 007bd20d  5f                   pop edi
// 007bd20e  5e                   pop esi
// 007bd20f  5d                   pop ebp
// 007bd210  5b                   pop ebx
// 007bd211  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?AlphaBlendU@CXTPCommandBarAnimation@@IAEXPAE0HH0E@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
