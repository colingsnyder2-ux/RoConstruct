// from server: 100% by auto
// roc 2009-12 00890480  unit: CXTPDockContext  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00890480
//
// 00890480  83ec10               sub esp, 0x10
// 00890483  56                   push esi
// 00890484  8d442404             lea eax, [esp + 4]
// 00890488  57                   push edi
// 00890489  50                   push eax
// 0089048a  e8e1c2faff           call 0x83c770
// 0089048f  8bc8                 mov ecx, eax
// 00890491  e8aabefaff           call 0x83c340
// 00890496  8b442414             mov eax, dword ptr [esp + 0x14]
// 0089049a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0089049e  2b4604               sub eax, dword ptr [esi + 4]
// 008904a1  8b3d6ccc9800         mov edi, dword ptr [0x98cc6c]
// 008904a7  83f80a               cmp eax, 0xa
// 008904aa  7d09                 jge 0x8904b5
// 008904ac  83c0f6               add eax, -0xa
// 008904af  50                   push eax
// 008904b0  6a00                 push 0
// 008904b2  56                   push esi
// 008904b3  ffd7                 call edi
// 008904b5  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008904b8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008904bc  8bd1                 mov edx, ecx
// 008904be  2bd0                 sub edx, eax
// 008904c0  83fa0a               cmp edx, 0xa
// 008904c3  7d0b                 jge 0x8904d0
// 008904c5  2bc1                 sub eax, ecx
// 008904c7  83c00a               add eax, 0xa
// 008904ca  50                   push eax
// 008904cb  6a00                 push 0
// 008904cd  56                   push esi
// 008904ce  ffd7                 call edi
// 008904d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 008904d4  2b06                 sub eax, dword ptr [esi]
// 008904d6  83f80a               cmp eax, 0xa
// 008904d9  7d09                 jge 0x8904e4
// 008904db  6a00                 push 0
// 008904dd  83c0f6               add eax, -0xa
// 008904e0  50                   push eax
// 008904e1  56                   push esi
// 008904e2  ffd7                 call edi
// 008904e4  8b4e08               mov ecx, dword ptr [esi + 8]
// 008904e7  8b442408             mov eax, dword ptr [esp + 8]
// 008904eb  8bd1                 mov edx, ecx
// 008904ed  2bd0                 sub edx, eax
// 008904ef  83fa0a               cmp edx, 0xa
// 008904f2  7d0b                 jge 0x8904ff
// 008904f4  2bc1                 sub eax, ecx
// 008904f6  6a00                 push 0
// 008904f8  83c00a               add eax, 0xa
// 008904fb  50                   push eax
// 008904fc  56                   push esi
// 008904fd  ffd7                 call edi
// 008904ff  5f                   pop edi
// 00890500  5e                   pop esi
// 00890501  83c410               add esp, 0x10
// 00890504  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockContext.cpp (function ?EnsureVisible@CXTPDockContext@@AAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockContext.cpp
