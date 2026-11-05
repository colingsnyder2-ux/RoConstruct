// from server: 100% by auto
// roc 2009-12 00871e50  unit: CXTPTabPaintManager::CAppearanceSetFlat  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00871e50
//
// 00871e50  53                   push ebx
// 00871e51  56                   push esi
// 00871e52  57                   push edi
// 00871e53  8bf1                 mov esi, ecx
// 00871e55  e886260600           call 0x8d44e0
// 00871e5a  8b1d38ca9800         mov ebx, dword ptr [0x98ca38]
// 00871e60  6a00                 push 0
// 00871e62  6a04                 push 4
// 00871e64  6a02                 push 2
// 00871e66  6a02                 push 2
// 00871e68  8d7e04               lea edi, [esi + 4]
// 00871e6b  57                   push edi
// 00871e6c  c706c40fa000         mov dword ptr [esi], 0xa00fc4
// 00871e72  ffd3                 call ebx
// 00871e74  8b442410             mov eax, dword ptr [esp + 0x10]
// 00871e78  6a00                 push 0
// 00871e7a  6a00                 push 0
// 00871e7c  6a01                 push 1
// 00871e7e  6a00                 push 0
// 00871e80  57                   push edi
// 00871e81  c7462401000000       mov dword ptr [esi + 0x24], 1
// 00871e88  c7462800000000       mov dword ptr [esi + 0x28], 0
// 00871e8f  c706d411a000         mov dword ptr [esi], 0xa011d4
// 00871e95  89462c               mov dword ptr [esi + 0x2c], eax
// 00871e98  ffd3                 call ebx
// 00871e9a  5f                   pop edi
// 00871e9b  8bc6                 mov eax, esi
// 00871e9d  5e                   pop esi
// 00871e9e  5b                   pop ebx
// 00871e9f  c20400               ret 4
// library xtp-13.2.1/Source\Ribbon\XTPRibbonPaintManager.cpp (function ??0CRibbonAppearanceSet@CXTPRibbonPaintManager@@QAE@PAV1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonPaintManager.cpp
