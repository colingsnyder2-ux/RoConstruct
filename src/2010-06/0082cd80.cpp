// from server: 100% by auto
// roc 2010-06 0082cd80  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0082cd80
//
// 0082cd80  53                   push ebx
// 0082cd81  56                   push esi
// 0082cd82  57                   push edi
// 0082cd83  8bf1                 mov esi, ecx
// 0082cd85  e806b90500           call 0x888690
// 0082cd8a  8b1dc0bb9e00         mov ebx, dword ptr [0x9ebbc0]
// 0082cd90  6a00                 push 0
// 0082cd92  6a04                 push 4
// 0082cd94  6a02                 push 2
// 0082cd96  6a02                 push 2
// 0082cd98  8d7e04               lea edi, [esi + 4]
// 0082cd9b  57                   push edi
// 0082cd9c  c7060459a600         mov dword ptr [esi], 0xa65904
// 0082cda2  ffd3                 call ebx
// 0082cda4  8b442410             mov eax, dword ptr [esp + 0x10]
// 0082cda8  6a00                 push 0
// 0082cdaa  6a00                 push 0
// 0082cdac  6a01                 push 1
// 0082cdae  6a00                 push 0
// 0082cdb0  57                   push edi
// 0082cdb1  c7462401000000       mov dword ptr [esi + 0x24], 1
// 0082cdb8  c7462800000000       mov dword ptr [esi + 0x28], 0
// 0082cdbf  c706145ba600         mov dword ptr [esi], 0xa65b14
// 0082cdc5  89462c               mov dword ptr [esi + 0x2c], eax
// 0082cdc8  ffd3                 call ebx
// 0082cdca  5f                   pop edi
// 0082cdcb  8bc6                 mov eax, esi
// 0082cdcd  5e                   pop esi
// 0082cdce  5b                   pop ebx
// 0082cdcf  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonPaintManager.cpp (function ??0CRibbonAppearanceSet@CXTPRibbonPaintManager@@QAE@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonPaintManager.cpp
