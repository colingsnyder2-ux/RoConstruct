// from server: 100% by auto
// roc 2009-12 007fdfa0  unit: CXTPPaintManager  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fdfa0
//
// 007fdfa0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007fdfa4  0faf442410           imul eax, dword ptr [esp + 0x10]
// 007fdfa9  8a542418             mov dl, byte ptr [esp + 0x18]
// 007fdfad  80c9ff               or cl, 0xff
// 007fdfb0  2aca                 sub cl, dl
// 007fdfb2  85c0                 test eax, eax
// 007fdfb4  7e6d                 jle 0x7fe023
// 007fdfb6  53                   push ebx
// 007fdfb7  55                   push ebp
// 007fdfb8  56                   push esi
// 007fdfb9  8b742420             mov esi, dword ptr [esp + 0x20]
// 007fdfbd  57                   push edi
// 007fdfbe  0fb6f9               movzx edi, cl
// 007fdfc1  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007fdfc5  89442428             mov dword ptr [esp + 0x28], eax
// 007fdfc9  8b442414             mov eax, dword ptr [esp + 0x14]
// 007fdfcd  0fb6ea               movzx ebp, dl
// 007fdfd0  0fb616               movzx edx, byte ptr [esi]
// 007fdfd3  0fb619               movzx ebx, byte ptr [ecx]
// 007fdfd6  0fafd5               imul edx, ebp
// 007fdfd9  0fafdf               imul ebx, edi
// 007fdfdc  03d3                 add edx, ebx
// 007fdfde  c1fa08               sar edx, 8
// 007fdfe1  8810                 mov byte ptr [eax], dl
// 007fdfe3  0fb65601             movzx edx, byte ptr [esi + 1]
// 007fdfe7  0fb65901             movzx ebx, byte ptr [ecx + 1]
// 007fdfeb  0fafd5               imul edx, ebp
// 007fdfee  0fafdf               imul ebx, edi
// 007fdff1  03d3                 add edx, ebx
// 007fdff3  c1fa08               sar edx, 8
// 007fdff6  885001               mov byte ptr [eax + 1], dl
// 007fdff9  0fb65602             movzx edx, byte ptr [esi + 2]
// 007fdffd  0fb65902             movzx ebx, byte ptr [ecx + 2]
// 007fe001  0fafd5               imul edx, ebp
// 007fe004  0fafdf               imul ebx, edi
// 007fe007  03d3                 add edx, ebx
// 007fe009  c1fa08               sar edx, 8
// 007fe00c  885002               mov byte ptr [eax + 2], dl
// 007fe00f  83c004               add eax, 4
// 007fe012  83c104               add ecx, 4
// 007fe015  83c604               add esi, 4
// 007fe018  836c242801           sub dword ptr [esp + 0x28], 1
// 007fe01d  75b1                 jne 0x7fdfd0
// 007fe01f  5f                   pop edi
// 007fe020  5e                   pop esi
// 007fe021  5d                   pop ebp
// 007fe022  5b                   pop ebx
// 007fe023  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?AlphaBlendU@CXTPPaintManager@@IAEXPAE0HH0E@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
