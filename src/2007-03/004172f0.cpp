// from server: 100% by auto
// roc 2007-03 004172f0  unit: seg_00410000  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004172f0
//
// 004172f0  56                   push esi
// 004172f1  6814298c00           push 0x8c2914
// 004172f6  e8b5e5ffff           call 0x4158b0
// 004172fb  8bf0                 mov esi, eax
// 004172fd  85f6                 test esi, esi
// 004172ff  7504                 jne 0x417305
// 00417301  5e                   pop esi
// 00417302  c21000               ret 0x10
// 00417305  8b06                 mov eax, dword ptr [esi]
// 00417307  8b5008               mov edx, dword ptr [eax + 8]
// 0041730a  57                   push edi
// 0041730b  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0041730f  56                   push esi
// 00417310  8bce                 mov ecx, esi
// 00417312  897e04               mov dword ptr [esi + 4], edi
// 00417315  ffd2                 call edx
// 00417317  50                   push eax
// 00417318  8d4e08               lea ecx, [esi + 8]
// 0041731b  e880d8ffff           call 0x414ba0
// 00417320  8b7614               mov esi, dword ptr [esi + 0x14]
// 00417323  56                   push esi
// 00417324  6afc                 push -4
// 00417326  57                   push edi
// 00417327  ff15e8ec7700         call dword ptr [0x77ece8]
// 0041732d  8b442418             mov eax, dword ptr [esp + 0x18]
// 00417331  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00417335  8b542410             mov edx, dword ptr [esp + 0x10]
// 00417339  50                   push eax
// 0041733a  51                   push ecx
// 0041733b  52                   push edx
// 0041733c  57                   push edi
// 0041733d  ffd6                 call esi
// 0041733f  5f                   pop edi
// 00417340  5e                   pop esi
// 00417341  c21000               ret 0x10
// library atl-8.0/atl.cpp (function ?StartWindowProc@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@SGJPAUHWND__@@IIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
