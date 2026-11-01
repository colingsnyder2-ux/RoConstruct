// from server: 100% by auto
// roc 2009-12 007fd670  unit: CXTPControlComboBoxAutoCompleteWnd  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fd670
//
// 007fd670  57                   push edi
// 007fd671  8b7c2408             mov edi, dword ptr [esp + 8]
// 007fd675  85ff                 test edi, edi
// 007fd677  7e24                 jle 0x7fd69d
// 007fd679  8b54240c             mov edx, dword ptr [esp + 0xc]
// 007fd67d  53                   push ebx
// 007fd67e  56                   push esi
// 007fd67f  8b742418             mov esi, dword ptr [esp + 0x18]
// 007fd683  2bf2                 sub esi, edx
// 007fd685  8b02                 mov eax, dword ptr [edx]
// 007fd687  8b1c16               mov ebx, dword ptr [esi + edx]
// 007fd68a  83c01e               add eax, 0x1e
// 007fd68d  8d0440               lea eax, [eax + eax*2]
// 007fd690  83c204               add edx, 4
// 007fd693  83ef01               sub edi, 1
// 007fd696  891c81               mov dword ptr [ecx + eax*4], ebx
// 007fd699  75ea                 jne 0x7fd685
// 007fd69b  5e                   pop esi
// 007fd69c  5b                   pop ebx
// 007fd69d  5f                   pop edi
// 007fd69e  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?SetColors@CXTPPaintManager@@QAEXHPBHPBK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
