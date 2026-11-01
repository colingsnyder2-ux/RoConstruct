// from server: 100% by auto
// roc 2007-03 006329f0  unit: seg_00630000  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006329f0
//
// 006329f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006329f4  0faf442410           imul eax, dword ptr [esp + 0x10]
// 006329f9  8a542418             mov dl, byte ptr [esp + 0x18]
// 006329fd  80c9ff               or cl, 0xff
// 00632a00  2aca                 sub cl, dl
// 00632a02  85c0                 test eax, eax
// 00632a04  7e6d                 jle 0x632a73
// 00632a06  53                   push ebx
// 00632a07  55                   push ebp
// 00632a08  56                   push esi
// 00632a09  8b742420             mov esi, dword ptr [esp + 0x20]
// 00632a0d  57                   push edi
// 00632a0e  0fb6f9               movzx edi, cl
// 00632a11  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00632a15  89442428             mov dword ptr [esp + 0x28], eax
// 00632a19  8b442414             mov eax, dword ptr [esp + 0x14]
// 00632a1d  0fb6ea               movzx ebp, dl
// 00632a20  0fb616               movzx edx, byte ptr [esi]
// 00632a23  0fb619               movzx ebx, byte ptr [ecx]
// 00632a26  0fafd5               imul edx, ebp
// 00632a29  0fafdf               imul ebx, edi
// 00632a2c  03d3                 add edx, ebx
// 00632a2e  c1fa08               sar edx, 8
// 00632a31  8810                 mov byte ptr [eax], dl
// 00632a33  0fb65601             movzx edx, byte ptr [esi + 1]
// 00632a37  0fb65901             movzx ebx, byte ptr [ecx + 1]
// 00632a3b  0fafd5               imul edx, ebp
// 00632a3e  0fafdf               imul ebx, edi
// 00632a41  03d3                 add edx, ebx
// 00632a43  c1fa08               sar edx, 8
// 00632a46  885001               mov byte ptr [eax + 1], dl
// 00632a49  0fb65602             movzx edx, byte ptr [esi + 2]
// 00632a4d  0fb65902             movzx ebx, byte ptr [ecx + 2]
// 00632a51  0fafd5               imul edx, ebp
// 00632a54  0fafdf               imul ebx, edi
// 00632a57  03d3                 add edx, ebx
// 00632a59  c1fa08               sar edx, 8
// 00632a5c  885002               mov byte ptr [eax + 2], dl
// 00632a5f  83c004               add eax, 4
// 00632a62  83c104               add ecx, 4
// 00632a65  83c604               add esi, 4
// 00632a68  836c242801           sub dword ptr [esp + 0x28], 1
// 00632a6d  75b1                 jne 0x632a20
// 00632a6f  5f                   pop edi
// 00632a70  5e                   pop esi
// 00632a71  5d                   pop ebp
// 00632a72  5b                   pop ebx
// 00632a73  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?AlphaBlendU@CXTPPaintManager@@IAEXPAE0HH0E@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
