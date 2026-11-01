// from server: 100% by auto
// roc 2009-06 007bd390  unit: CXTPRibbonBar  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007bd390
//
// 007bd390  56                   push esi
// 007bd391  8b742408             mov esi, dword ptr [esp + 8]
// 007bd395  57                   push edi
// 007bd396  8bf9                 mov edi, ecx
// 007bd398  85f6                 test esi, esi
// 007bd39a  7d05                 jge 0x7bd3a1
// 007bd39c  e843b9f5ff           call 0x718ce4
// 007bd3a1  3b7708               cmp esi, dword ptr [edi + 8]
// 007bd3a4  7c0b                 jl 0x7bd3b1
// 007bd3a6  6aff                 push -1
// 007bd3a8  8d4601               lea eax, [esi + 1]
// 007bd3ab  50                   push eax
// 007bd3ac  e88ffeffff           call 0x7bd240
// 007bd3b1  8b442410             mov eax, dword ptr [esp + 0x10]
// 007bd3b5  8b08                 mov ecx, dword ptr [eax]
// 007bd3b7  c1e604               shl esi, 4
// 007bd3ba  037704               add esi, dword ptr [edi + 4]
// 007bd3bd  5f                   pop edi
// 007bd3be  890e                 mov dword ptr [esi], ecx
// 007bd3c0  8b5004               mov edx, dword ptr [eax + 4]
// 007bd3c3  895604               mov dword ptr [esi + 4], edx
// 007bd3c6  8b4808               mov ecx, dword ptr [eax + 8]
// 007bd3c9  894e08               mov dword ptr [esi + 8], ecx
// 007bd3cc  8b500c               mov edx, dword ptr [eax + 0xc]
// 007bd3cf  89560c               mov dword ptr [esi + 0xc], edx
// 007bd3d2  5e                   pop esi
// 007bd3d3  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?SetAtGrow@?$CArray@UtagRECT@@AAU1@@@QAEXHAAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
