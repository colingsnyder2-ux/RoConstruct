// from server: 100% by auto
// roc 2010-06 00809570  unit: PAUHWND__::?$CArray  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00809570
//
// 00809570  56                   push esi
// 00809571  8b742408             mov esi, dword ptr [esp + 8]
// 00809575  57                   push edi
// 00809576  8bf9                 mov edi, ecx
// 00809578  85f6                 test esi, esi
// 0080957a  7d05                 jge 0x809581
// 0080957c  e8cbe6f9ff           call 0x7a7c4c
// 00809581  3b7708               cmp esi, dword ptr [edi + 8]
// 00809584  7c0b                 jl 0x809591
// 00809586  6aff                 push -1
// 00809588  8d4601               lea eax, [esi + 1]
// 0080958b  50                   push eax
// 0080958c  e88ffeffff           call 0x809420
// 00809591  8b442410             mov eax, dword ptr [esp + 0x10]
// 00809595  8b08                 mov ecx, dword ptr [eax]
// 00809597  c1e604               shl esi, 4
// 0080959a  037704               add esi, dword ptr [edi + 4]
// 0080959d  5f                   pop edi
// 0080959e  890e                 mov dword ptr [esi], ecx
// 008095a0  8b5004               mov edx, dword ptr [eax + 4]
// 008095a3  895604               mov dword ptr [esi + 4], edx
// 008095a6  8b4808               mov ecx, dword ptr [eax + 8]
// 008095a9  894e08               mov dword ptr [esi + 8], ecx
// 008095ac  8b500c               mov edx, dword ptr [eax + 0xc]
// 008095af  89560c               mov dword ptr [esi + 0xc], edx
// 008095b2  5e                   pop esi
// 008095b3  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPCommandBarAnimation.cpp (function ?SetAtGrow@?$CArray@UtagRECT@@AAU1@@@QAEXHAAUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBarAnimation.cpp
