// from server: 100% by auto
// roc 2008-06 00418970  unit: VCLuaFunction::?$CComAggObject  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00418970
//
// 00418970  56                   push esi
// 00418971  6814f39700           push 0x97f314
// 00418976  e8a5efffff           call 0x417920
// 0041897b  8bf0                 mov esi, eax
// 0041897d  85f6                 test esi, esi
// 0041897f  7504                 jne 0x418985
// 00418981  5e                   pop esi
// 00418982  c21000               ret 0x10
// 00418985  8b06                 mov eax, dword ptr [esi]
// 00418987  8b5008               mov edx, dword ptr [eax + 8]
// 0041898a  57                   push edi
// 0041898b  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041898f  56                   push esi
// 00418990  8bce                 mov ecx, esi
// 00418992  897e04               mov dword ptr [esi + 4], edi
// 00418995  ffd2                 call edx
// 00418997  50                   push eax
// 00418998  8d4e08               lea ecx, [esi + 8]
// 0041899b  e820e7ffff           call 0x4170c0
// 004189a0  8b7614               mov esi, dword ptr [esi + 0x14]
// 004189a3  56                   push esi
// 004189a4  6afc                 push -4
// 004189a6  57                   push edi
// 004189a7  ff15d82d8000         call dword ptr [0x802dd8]
// 004189ad  8b442418             mov eax, dword ptr [esp + 0x18]
// 004189b1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004189b5  8b542410             mov edx, dword ptr [esp + 0x10]
// 004189b9  50                   push eax
// 004189ba  51                   push ecx
// 004189bb  52                   push edx
// 004189bc  57                   push edi
// 004189bd  ffd6                 call esi
// 004189bf  5f                   pop edi
// 004189c0  5e                   pop esi
// 004189c1  c21000               ret 0x10
// library atl-8.0/atl.cpp (function ?StartWindowProc@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@SGJPAUHWND__@@IIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
