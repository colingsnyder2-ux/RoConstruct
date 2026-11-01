// from server: 100% by auto
// roc 2011-06 00889e10  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00889e10
//
// 00889e10  53                   push ebx
// 00889e11  56                   push esi
// 00889e12  57                   push edi
// 00889e13  8bf1                 mov esi, ecx
// 00889e15  e8b6f70400           call 0x8d95d0
// 00889e1a  8b1dc81ba400         mov ebx, dword ptr [0xa41bc8]
// 00889e20  6a00                 push 0
// 00889e22  6a04                 push 4
// 00889e24  6a02                 push 2
// 00889e26  6a02                 push 2
// 00889e28  8d7e04               lea edi, [esi + 4]
// 00889e2b  57                   push edi
// 00889e2c  c7062403ad00         mov dword ptr [esi], 0xad0324
// 00889e32  ffd3                 call ebx
// 00889e34  8b442410             mov eax, dword ptr [esp + 0x10]
// 00889e38  6a00                 push 0
// 00889e3a  6a00                 push 0
// 00889e3c  6a01                 push 1
// 00889e3e  6a00                 push 0
// 00889e40  57                   push edi
// 00889e41  c7462401000000       mov dword ptr [esi + 0x24], 1
// 00889e48  c7462800000000       mov dword ptr [esi + 0x28], 0
// 00889e4f  c7063405ad00         mov dword ptr [esi], 0xad0534
// 00889e55  89462c               mov dword ptr [esi + 0x2c], eax
// 00889e58  ffd3                 call ebx
// 00889e5a  5f                   pop edi
// 00889e5b  8bc6                 mov eax, esi
// 00889e5d  5e                   pop esi
// 00889e5e  5b                   pop ebx
// 00889e5f  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonPaintManager.cpp (function ??0CRibbonAppearanceSet@CXTPRibbonPaintManager@@QAE@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonPaintManager.cpp
