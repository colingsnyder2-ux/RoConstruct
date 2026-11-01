// from server: 100% by auto
// roc 2010-06 007ef2b0  unit: CXTPToolBar::CControlButtonExpand  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef2b0
//
// 007ef2b0  56                   push esi
// 007ef2b1  8bf1                 mov esi, ecx
// 007ef2b3  e8c8adfbff           call 0x7aa080
// 007ef2b8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007ef2bc  8b10                 mov edx, dword ptr [eax]
// 007ef2be  8b9290000000         mov edx, dword ptr [edx + 0x90]
// 007ef2c4  51                   push ecx
// 007ef2c5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007ef2c9  56                   push esi
// 007ef2ca  51                   push ecx
// 007ef2cb  8bc8                 mov ecx, eax
// 007ef2cd  ffd2                 call edx
// 007ef2cf  5e                   pop esi
// 007ef2d0  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPControlPopup.cpp (function ?AdjustExcludeRect@CXTPControlPopup@@UAEXAAVCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPControlPopup.cpp
