// from server: 100% by auto
// roc 2011-06 00850b00  unit: CXTPToolBar::CControlButtonExpand  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00850b00
//
// 00850b00  56                   push esi
// 00850b01  8bf1                 mov esi, ecx
// 00850b03  e858bcfbff           call 0x80c760
// 00850b08  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00850b0c  8b10                 mov edx, dword ptr [eax]
// 00850b0e  8b9290000000         mov edx, dword ptr [edx + 0x90]
// 00850b14  51                   push ecx
// 00850b15  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00850b19  56                   push esi
// 00850b1a  51                   push ecx
// 00850b1b  8bc8                 mov ecx, eax
// 00850b1d  ffd2                 call edx
// 00850b1f  5e                   pop esi
// 00850b20  c20800               ret 8
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPControlPopup.cpp (function ?AdjustExcludeRect@CXTPControlPopup@@UAEXAAVCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPControlPopup.cpp
