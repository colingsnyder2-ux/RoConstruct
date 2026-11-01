// from server: 100% by auto
// roc 2007-03 0068e4c0  unit: seg_00680000  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0068e4c0
//
// 0068e4c0  53                   push ebx
// 0068e4c1  56                   push esi
// 0068e4c2  57                   push edi
// 0068e4c3  8bf1                 mov esi, ecx
// 0068e4c5  e896950700           call 0x707a60
// 0068e4ca  8b1db4ed7700         mov ebx, dword ptr [0x77edb4]
// 0068e4d0  6a00                 push 0
// 0068e4d2  6a04                 push 4
// 0068e4d4  6a02                 push 2
// 0068e4d6  6a02                 push 2
// 0068e4d8  8d7e04               lea edi, [esi + 4]
// 0068e4db  57                   push edi
// 0068e4dc  c706ec017d00         mov dword ptr [esi], 0x7d01ec
// 0068e4e2  ffd3                 call ebx
// 0068e4e4  8b442410             mov eax, dword ptr [esp + 0x10]
// 0068e4e8  6a00                 push 0
// 0068e4ea  6a00                 push 0
// 0068e4ec  6a01                 push 1
// 0068e4ee  6a00                 push 0
// 0068e4f0  57                   push edi
// 0068e4f1  c7462401000000       mov dword ptr [esi + 0x24], 1
// 0068e4f8  c7462800000000       mov dword ptr [esi + 0x28], 0
// 0068e4ff  c706f4037d00         mov dword ptr [esi], 0x7d03f4
// 0068e505  89462c               mov dword ptr [esi + 0x2c], eax
// 0068e508  ffd3                 call ebx
// 0068e50a  5f                   pop edi
// 0068e50b  8bc6                 mov eax, esi
// 0068e50d  5e                   pop esi
// 0068e50e  5b                   pop ebx
// 0068e50f  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonPaintManager.cpp (function ??0CRibbonAppearanceSet@CXTPRibbonPaintManager@@QAE@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonPaintManager.cpp
