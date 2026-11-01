// from server: 100% by auto
// roc 2012-06 004253f0  unit: RBX::FunctionMarshaller  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004253f0
//
// 004253f0  56                   push esi
// 004253f1  68c4a4e500           push 0xe5a4c4
// 004253f6  e845feffff           call 0x425240
// 004253fb  8bf0                 mov esi, eax
// 004253fd  85f6                 test esi, esi
// 004253ff  7504                 jne 0x425405
// 00425401  5e                   pop esi
// 00425402  c21000               ret 0x10
// 00425405  8b06                 mov eax, dword ptr [esi]
// 00425407  8b5008               mov edx, dword ptr [eax + 8]
// 0042540a  57                   push edi
// 0042540b  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0042540f  56                   push esi
// 00425410  8bce                 mov ecx, esi
// 00425412  897e04               mov dword ptr [esi + 4], edi
// 00425415  ffd2                 call edx
// 00425417  50                   push eax
// 00425418  8d4e08               lea ecx, [esi + 8]
// 0042541b  e8d0f9ffff           call 0x424df0
// 00425420  8b7614               mov esi, dword ptr [esi + 0x14]
// 00425423  56                   push esi
// 00425424  6afc                 push -4
// 00425426  57                   push edi
// 00425427  ff15943ab200         call dword ptr [0xb23a94]
// 0042542d  8b442418             mov eax, dword ptr [esp + 0x18]
// 00425431  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00425435  8b542410             mov edx, dword ptr [esp + 0x10]
// 00425439  50                   push eax
// 0042543a  51                   push ecx
// 0042543b  52                   push edx
// 0042543c  57                   push edi
// 0042543d  ffd6                 call esi
// 0042543f  5f                   pop edi
// 00425440  5e                   pop esi
// 00425441  c21000               ret 0x10
// library atl-8.0/atl.cpp (function ?StartWindowProc@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@SGJPAUHWND__@@IIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
