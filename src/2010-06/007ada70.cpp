// from server: 100% by auto
// roc 2010-06 007ada70  unit: CXTPPaintManager  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ada70
//
// 007ada70  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007ada74  0faf442410           imul eax, dword ptr [esp + 0x10]
// 007ada79  8a542418             mov dl, byte ptr [esp + 0x18]
// 007ada7d  80c9ff               or cl, 0xff
// 007ada80  2aca                 sub cl, dl
// 007ada82  85c0                 test eax, eax
// 007ada84  7e6d                 jle 0x7adaf3
// 007ada86  53                   push ebx
// 007ada87  55                   push ebp
// 007ada88  56                   push esi
// 007ada89  8b742420             mov esi, dword ptr [esp + 0x20]
// 007ada8d  57                   push edi
// 007ada8e  0fb6f9               movzx edi, cl
// 007ada91  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007ada95  89442428             mov dword ptr [esp + 0x28], eax
// 007ada99  8b442414             mov eax, dword ptr [esp + 0x14]
// 007ada9d  0fb6ea               movzx ebp, dl
// 007adaa0  0fb616               movzx edx, byte ptr [esi]
// 007adaa3  0fb619               movzx ebx, byte ptr [ecx]
// 007adaa6  0fafd5               imul edx, ebp
// 007adaa9  0fafdf               imul ebx, edi
// 007adaac  03d3                 add edx, ebx
// 007adaae  c1fa08               sar edx, 8
// 007adab1  8810                 mov byte ptr [eax], dl
// 007adab3  0fb65601             movzx edx, byte ptr [esi + 1]
// 007adab7  0fb65901             movzx ebx, byte ptr [ecx + 1]
// 007adabb  0fafd5               imul edx, ebp
// 007adabe  0fafdf               imul ebx, edi
// 007adac1  03d3                 add edx, ebx
// 007adac3  c1fa08               sar edx, 8
// 007adac6  885001               mov byte ptr [eax + 1], dl
// 007adac9  0fb65602             movzx edx, byte ptr [esi + 2]
// 007adacd  0fb65902             movzx ebx, byte ptr [ecx + 2]
// 007adad1  0fafd5               imul edx, ebp
// 007adad4  0fafdf               imul ebx, edi
// 007adad7  03d3                 add edx, ebx
// 007adad9  c1fa08               sar edx, 8
// 007adadc  885002               mov byte ptr [eax + 2], dl
// 007adadf  83c004               add eax, 4
// 007adae2  83c104               add ecx, 4
// 007adae5  83c604               add esi, 4
// 007adae8  836c242801           sub dword ptr [esp + 0x28], 1
// 007adaed  75b1                 jne 0x7adaa0
// 007adaef  5f                   pop edi
// 007adaf0  5e                   pop esi
// 007adaf1  5d                   pop ebp
// 007adaf2  5b                   pop ebx
// 007adaf3  c21800               ret 0x18
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?AlphaBlendU@CXTPPaintManager@@IAEXPAE0HH0E@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
