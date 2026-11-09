// from server: 100% by auto
// roc 2010-06 0086e1b0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetWhidbey  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0086e1b0
//
// 0086e1b0  8b442418             mov eax, dword ptr [esp + 0x18]
// 0086e1b4  56                   push esi
// 0086e1b5  57                   push edi
// 0086e1b6  8bf9                 mov edi, ecx
// 0086e1b8  85c0                 test eax, eax
// 0086e1ba  7409                 je 0x86e1c5
// 0086e1bc  0558ffffff           add eax, 0xffffff58
// 0086e1c1  8bf0                 mov esi, eax
// 0086e1c3  eb04                 jmp 0x86e1c9
// 0086e1c5  33c0                 xor eax, eax
// 0086e1c7  33f6                 xor esi, esi
// 0086e1c9  8d4854               lea ecx, [eax + 0x54]
// 0086e1cc  8b01                 mov eax, dword ptr [ecx]
// 0086e1ce  8b5018               mov edx, dword ptr [eax + 0x18]
// 0086e1d1  ffd2                 call edx
// 0086e1d3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0086e1d7  8b542414             mov edx, dword ptr [esp + 0x14]
// 0086e1db  6a01                 push 1
// 0086e1dd  83c704               add edi, 4
// 0086e1e0  57                   push edi
// 0086e1e1  50                   push eax
// 0086e1e2  56                   push esi
// 0086e1e3  83ec10               sub esp, 0x10
// 0086e1e6  8bc4                 mov eax, esp
// 0086e1e8  8908                 mov dword ptr [eax], ecx
// 0086e1ea  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0086e1ee  895004               mov dword ptr [eax + 4], edx
// 0086e1f1  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0086e1f5  894808               mov dword ptr [eax + 8], ecx
// 0086e1f8  89500c               mov dword ptr [eax + 0xc], edx
// 0086e1fb  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0086e1ff  50                   push eax
// 0086e200  e83bbaffff           call 0x869c40
// 0086e205  83c424               add esp, 0x24
// 0086e208  5f                   pop edi
// 0086e209  5e                   pop esi
// 0086e20a  c21800               ret 0x18
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?FillHeader@CColorSetVisualStudio2005@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEXPAVCDC@@VCRect@@PAVCXTPTabManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
