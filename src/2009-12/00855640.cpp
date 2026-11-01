// from server: 100% by auto
// roc 2009-12 00855640  unit: PAUHWND__::?$CArray  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00855640
//
// 00855640  56                   push esi
// 00855641  8b742408             mov esi, dword ptr [esp + 8]
// 00855645  57                   push edi
// 00855646  8bf9                 mov edi, ecx
// 00855648  85f6                 test esi, esi
// 0085564a  7d05                 jge 0x855651
// 0085564c  e8bbe4f9ff           call 0x7f3b0c
// 00855651  3b7708               cmp esi, dword ptr [edi + 8]
// 00855654  7c0b                 jl 0x855661
// 00855656  6aff                 push -1
// 00855658  8d4601               lea eax, [esi + 1]
// 0085565b  50                   push eax
// 0085565c  e88ffeffff           call 0x8554f0
// 00855661  8b442410             mov eax, dword ptr [esp + 0x10]
// 00855665  8b08                 mov ecx, dword ptr [eax]
// 00855667  c1e604               shl esi, 4
// 0085566a  037704               add esi, dword ptr [edi + 4]
// 0085566d  5f                   pop edi
// 0085566e  890e                 mov dword ptr [esi], ecx
// 00855670  8b5004               mov edx, dword ptr [eax + 4]
// 00855673  895604               mov dword ptr [esi + 4], edx
// 00855676  8b4808               mov ecx, dword ptr [eax + 8]
// 00855679  894e08               mov dword ptr [esi + 8], ecx
// 0085567c  8b500c               mov edx, dword ptr [eax + 0xc]
// 0085567f  89560c               mov dword ptr [esi + 0xc], edx
// 00855682  5e                   pop esi
// 00855683  c20800               ret 8
// library xtp-15.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?SetAtGrow@?$CArray@UtagRECT@@AAU1@@@QAEXHAAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
