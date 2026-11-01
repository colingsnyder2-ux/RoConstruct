// from server: 100% by auto
// roc 2009-06 007230e0  unit: CXTPPaintManager  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007230e0
//
// 007230e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007230e4  0faf442410           imul eax, dword ptr [esp + 0x10]
// 007230e9  8a542418             mov dl, byte ptr [esp + 0x18]
// 007230ed  80c9ff               or cl, 0xff
// 007230f0  2aca                 sub cl, dl
// 007230f2  85c0                 test eax, eax
// 007230f4  7e6d                 jle 0x723163
// 007230f6  53                   push ebx
// 007230f7  55                   push ebp
// 007230f8  56                   push esi
// 007230f9  8b742420             mov esi, dword ptr [esp + 0x20]
// 007230fd  57                   push edi
// 007230fe  0fb6f9               movzx edi, cl
// 00723101  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00723105  89442428             mov dword ptr [esp + 0x28], eax
// 00723109  8b442414             mov eax, dword ptr [esp + 0x14]
// 0072310d  0fb6ea               movzx ebp, dl
// 00723110  0fb616               movzx edx, byte ptr [esi]
// 00723113  0fb619               movzx ebx, byte ptr [ecx]
// 00723116  0fafd5               imul edx, ebp
// 00723119  0fafdf               imul ebx, edi
// 0072311c  03d3                 add edx, ebx
// 0072311e  c1fa08               sar edx, 8
// 00723121  8810                 mov byte ptr [eax], dl
// 00723123  0fb65601             movzx edx, byte ptr [esi + 1]
// 00723127  0fb65901             movzx ebx, byte ptr [ecx + 1]
// 0072312b  0fafd5               imul edx, ebp
// 0072312e  0fafdf               imul ebx, edi
// 00723131  03d3                 add edx, ebx
// 00723133  c1fa08               sar edx, 8
// 00723136  885001               mov byte ptr [eax + 1], dl
// 00723139  0fb65602             movzx edx, byte ptr [esi + 2]
// 0072313d  0fb65902             movzx ebx, byte ptr [ecx + 2]
// 00723141  0fafd5               imul edx, ebp
// 00723144  0fafdf               imul ebx, edi
// 00723147  03d3                 add edx, ebx
// 00723149  c1fa08               sar edx, 8
// 0072314c  885002               mov byte ptr [eax + 2], dl
// 0072314f  83c004               add eax, 4
// 00723152  83c104               add ecx, 4
// 00723155  83c604               add esi, 4
// 00723158  836c242801           sub dword ptr [esp + 0x28], 1
// 0072315d  75b1                 jne 0x723110
// 0072315f  5f                   pop edi
// 00723160  5e                   pop esi
// 00723161  5d                   pop ebp
// 00723162  5b                   pop ebx
// 00723163  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?AlphaBlendU@CXTPPaintManager@@IAEXPAE0HH0E@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
