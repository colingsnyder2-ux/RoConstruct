// from server: 100% by auto
// roc 2009-12 008ba080  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetWhidbey  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008ba080
//
// 008ba080  8b442418             mov eax, dword ptr [esp + 0x18]
// 008ba084  56                   push esi
// 008ba085  57                   push edi
// 008ba086  8bf9                 mov edi, ecx
// 008ba088  85c0                 test eax, eax
// 008ba08a  7409                 je 0x8ba095
// 008ba08c  0558ffffff           add eax, 0xffffff58
// 008ba091  8bf0                 mov esi, eax
// 008ba093  eb04                 jmp 0x8ba099
// 008ba095  33c0                 xor eax, eax
// 008ba097  33f6                 xor esi, esi
// 008ba099  8d4854               lea ecx, [eax + 0x54]
// 008ba09c  8b01                 mov eax, dword ptr [ecx]
// 008ba09e  8b5018               mov edx, dword ptr [eax + 0x18]
// 008ba0a1  ffd2                 call edx
// 008ba0a3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008ba0a7  8b542414             mov edx, dword ptr [esp + 0x14]
// 008ba0ab  6a01                 push 1
// 008ba0ad  83c704               add edi, 4
// 008ba0b0  57                   push edi
// 008ba0b1  50                   push eax
// 008ba0b2  56                   push esi
// 008ba0b3  83ec10               sub esp, 0x10
// 008ba0b6  8bc4                 mov eax, esp
// 008ba0b8  8908                 mov dword ptr [eax], ecx
// 008ba0ba  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 008ba0be  895004               mov dword ptr [eax + 4], edx
// 008ba0c1  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 008ba0c5  894808               mov dword ptr [eax + 8], ecx
// 008ba0c8  89500c               mov dword ptr [eax + 0xc], edx
// 008ba0cb  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008ba0cf  50                   push eax
// 008ba0d0  e87bbaffff           call 0x8b5b50
// 008ba0d5  83c424               add esp, 0x24
// 008ba0d8  5f                   pop edi
// 008ba0d9  5e                   pop esi
// 008ba0da  c21800               ret 0x18
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?FillHeader@CColorSetVisualStudio2005@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEXPAVCDC@@VCRect@@PAVCXTPTabManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
