// from server: 100% by auto
// roc 2010-06 00835290  unit: CXTPOffice2007Theme  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00835290
//
// 00835290  83ec10               sub esp, 0x10
// 00835293  8b442420             mov eax, dword ptr [esp + 0x20]
// 00835297  53                   push ebx
// 00835298  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0083529c  55                   push ebp
// 0083529d  bd03000000           mov ebp, 3
// 008352a2  56                   push esi
// 008352a3  83c0fd               add eax, -3
// 008352a6  83c3fd               add ebx, -3
// 008352a9  57                   push edi
// 008352aa  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 008352ae  894c2414             mov dword ptr [esp + 0x14], ecx
// 008352b2  89442418             mov dword ptr [esp + 0x18], eax
// 008352b6  896c2410             mov dword ptr [esp + 0x10], ebp
// 008352ba  85ed                 test ebp, ebp
// 008352bc  7e41                 jle 0x8352ff
// 008352be  8b742418             mov esi, dword ptr [esp + 0x18]
// 008352c2  68ffffff00           push 0xffffff
// 008352c7  6a02                 push 2
// 008352c9  6a02                 push 2
// 008352cb  8d4301               lea eax, [ebx + 1]
// 008352ce  50                   push eax
// 008352cf  8d4e01               lea ecx, [esi + 1]
// 008352d2  51                   push ecx
// 008352d3  8bcf                 mov ecx, edi
// 008352d5  e8b07a1400           call 0x97cd8a
// 008352da  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 008352de  6a27                 push 0x27
// 008352e0  e82b7ef7ff           call 0x7ad110
// 008352e5  50                   push eax
// 008352e6  6a02                 push 2
// 008352e8  6a02                 push 2
// 008352ea  53                   push ebx
// 008352eb  56                   push esi
// 008352ec  8bcf                 mov ecx, edi
// 008352ee  e8977a1400           call 0x97cd8a
// 008352f3  83ee04               sub esi, 4
// 008352f6  83ed01               sub ebp, 1
// 008352f9  75c7                 jne 0x8352c2
// 008352fb  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 008352ff  4d                   dec ebp
// 00835300  83eb04               sub ebx, 4
// 00835303  896c2410             mov dword ptr [esp + 0x10], ebp
// 00835307  85ed                 test ebp, ebp
// 00835309  7fb3                 jg 0x8352be
// 0083530b  5f                   pop edi
// 0083530c  5e                   pop esi
// 0083530d  5d                   pop ebp
// 0083530e  5b                   pop ebx
// 0083530f  83c410               add esp, 0x10
// 00835312  c21400               ret 0x14
// library xtp-13.2.1/Source\CommandBars\XTPOffice2007Theme.cpp (function ?DrawStatusBarGripper@CXTPOffice2007Theme@@MAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPOffice2007Theme.cpp
