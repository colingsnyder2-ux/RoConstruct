// from server: 100% by auto
// roc 2009-06 007954b0  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007954b0
//
// 007954b0  53                   push ebx
// 007954b1  56                   push esi
// 007954b2  57                   push edi
// 007954b3  8bf1                 mov esi, ecx
// 007954b5  e886440600           call 0x7f9940
// 007954ba  8b1da4ed8900         mov ebx, dword ptr [0x89eda4]
// 007954c0  6a00                 push 0
// 007954c2  6a04                 push 4
// 007954c4  6a02                 push 2
// 007954c6  6a02                 push 2
// 007954c8  8d7e04               lea edi, [esi + 4]
// 007954cb  57                   push edi
// 007954cc  c706e4039000         mov dword ptr [esi], 0x9003e4
// 007954d2  ffd3                 call ebx
// 007954d4  8b442410             mov eax, dword ptr [esp + 0x10]
// 007954d8  6a00                 push 0
// 007954da  6a00                 push 0
// 007954dc  6a01                 push 1
// 007954de  6a00                 push 0
// 007954e0  57                   push edi
// 007954e1  c7462401000000       mov dword ptr [esi + 0x24], 1
// 007954e8  c7462800000000       mov dword ptr [esi + 0x28], 0
// 007954ef  c706f4059000         mov dword ptr [esi], 0x9005f4
// 007954f5  89462c               mov dword ptr [esi + 0x2c], eax
// 007954f8  ffd3                 call ebx
// 007954fa  5f                   pop edi
// 007954fb  8bc6                 mov eax, esi
// 007954fd  5e                   pop esi
// 007954fe  5b                   pop ebx
// 007954ff  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonPaintManager.cpp (function ??0CRibbonAppearanceSet@CXTPRibbonPaintManager@@QAE@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonPaintManager.cpp
