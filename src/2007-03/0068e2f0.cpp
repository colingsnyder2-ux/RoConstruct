// from server: 100% by auto
// roc 2007-03 0068e2f0  unit: seg_00680000  size: 56 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068e2f0
//
// 0068e2f0  56                   push esi
// 0068e2f1  8bf1                 mov esi, ecx
// 0068e2f3  e868970700           call 0x707a60
// 0068e2f8  6a00                 push 0
// 0068e2fa  6a04                 push 4
// 0068e2fc  6a02                 push 2
// 0068e2fe  6a02                 push 2
// 0068e300  8d4604               lea eax, [esi + 4]
// 0068e303  50                   push eax
// 0068e304  c706ec017d00         mov dword ptr [esi], 0x7d01ec
// 0068e30a  ff15b4ed7700         call dword ptr [0x77edb4]
// 0068e310  c70634027d00         mov dword ptr [esi], 0x7d0234
// 0068e316  c7462401000000       mov dword ptr [esi + 0x24], 1
// 0068e31d  c7462800000000       mov dword ptr [esi + 0x28], 0
// 0068e324  8bc6                 mov eax, esi
// 0068e326  5e                   pop esi
// 0068e327  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ??0CAppearanceSetPropertyPageFlat@CXTPTabPaintManager@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
