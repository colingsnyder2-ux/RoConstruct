// from server: 100% by auto
// roc 2009-06 007df570  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetWhidbey  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007df570
//
// 007df570  8b442418             mov eax, dword ptr [esp + 0x18]
// 007df574  56                   push esi
// 007df575  57                   push edi
// 007df576  8bf9                 mov edi, ecx
// 007df578  85c0                 test eax, eax
// 007df57a  7409                 je 0x7df585
// 007df57c  0558ffffff           add eax, 0xffffff58
// 007df581  8bf0                 mov esi, eax
// 007df583  eb04                 jmp 0x7df589
// 007df585  33c0                 xor eax, eax
// 007df587  33f6                 xor esi, esi
// 007df589  8d4854               lea ecx, [eax + 0x54]
// 007df58c  8b01                 mov eax, dword ptr [ecx]
// 007df58e  8b5018               mov edx, dword ptr [eax + 0x18]
// 007df591  ffd2                 call edx
// 007df593  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007df597  8b542414             mov edx, dword ptr [esp + 0x14]
// 007df59b  6a01                 push 1
// 007df59d  83c704               add edi, 4
// 007df5a0  57                   push edi
// 007df5a1  50                   push eax
// 007df5a2  56                   push esi
// 007df5a3  83ec10               sub esp, 0x10
// 007df5a6  8bc4                 mov eax, esp
// 007df5a8  8908                 mov dword ptr [eax], ecx
// 007df5aa  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007df5ae  895004               mov dword ptr [eax + 4], edx
// 007df5b1  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 007df5b5  894808               mov dword ptr [eax + 8], ecx
// 007df5b8  89500c               mov dword ptr [eax + 0xc], edx
// 007df5bb  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007df5bf  50                   push eax
// 007df5c0  e85bbaffff           call 0x7db020
// 007df5c5  83c424               add esp, 0x24
// 007df5c8  5f                   pop edi
// 007df5c9  5e                   pop esi
// 007df5ca  c21800               ret 0x18
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?FillHeader@CColorSetVisualStudio2005@CXTPDockingPaneVisualStudio2005Beta1Theme@XTPDockingPanePaintThemes@@UAEXPAVCDC@@VCRect@@PAVCXTPTabManager@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
