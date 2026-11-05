// from server: 100% by auto
// roc 2011-06 00421990  unit: RBX::FunctionMarshaller  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00421990
//
// 00421990  56                   push esi
// 00421991  687c93d100           push 0xd1937c
// 00421996  e825ffffff           call 0x4218c0
// 0042199b  8bf0                 mov esi, eax
// 0042199d  85f6                 test esi, esi
// 0042199f  7504                 jne 0x4219a5
// 004219a1  5e                   pop esi
// 004219a2  c21000               ret 0x10
// 004219a5  8b06                 mov eax, dword ptr [esi]
// 004219a7  8b5008               mov edx, dword ptr [eax + 8]
// 004219aa  57                   push edi
// 004219ab  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 004219af  56                   push esi
// 004219b0  8bce                 mov ecx, esi
// 004219b2  897e04               mov dword ptr [esi + 4], edi
// 004219b5  ffd2                 call edx
// 004219b7  50                   push eax
// 004219b8  8d4e08               lea ecx, [esi + 8]
// 004219bb  e840fdffff           call 0x421700
// 004219c0  8b7614               mov esi, dword ptr [esi + 0x14]
// 004219c3  56                   push esi
// 004219c4  6afc                 push -4
// 004219c6  57                   push edi
// 004219c7  ff15001aa400         call dword ptr [0xa41a00]
// 004219cd  8b442418             mov eax, dword ptr [esp + 0x18]
// 004219d1  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004219d5  8b542410             mov edx, dword ptr [esp + 0x10]
// 004219d9  50                   push eax
// 004219da  51                   push ecx
// 004219db  52                   push edx
// 004219dc  57                   push edi
// 004219dd  ffd6                 call esi
// 004219df  5f                   pop edi
// 004219e0  5e                   pop esi
// 004219e1  c21000               ret 0x10
// library atl-8.0/atl.cpp (function ?StartWindowProc@?$CWindowImplBaseT@VCWindow@ATL@@V?$CWinTraits@$0FGAAAAAA@$0A@@2@@ATL@@SGJPAUHWND__@@IIJ@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
