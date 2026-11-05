// from server: 100% by auto
// roc 2010-06 00844680  unit: CXTPDockContext  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00844680
//
// 00844680  83ec10               sub esp, 0x10
// 00844683  56                   push esi
// 00844684  8d442404             lea eax, [esp + 4]
// 00844688  57                   push edi
// 00844689  50                   push eax
// 0084468a  e841c2faff           call 0x7f08d0
// 0084468f  8bc8                 mov ecx, eax
// 00844691  e80abefaff           call 0x7f04a0
// 00844696  8b442414             mov eax, dword ptr [esp + 0x14]
// 0084469a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0084469e  2b4604               sub eax, dword ptr [esi + 4]
// 008446a1  8b3d40bc9e00         mov edi, dword ptr [0x9ebc40]
// 008446a7  83f80a               cmp eax, 0xa
// 008446aa  7d09                 jge 0x8446b5
// 008446ac  83c0f6               add eax, -0xa
// 008446af  50                   push eax
// 008446b0  6a00                 push 0
// 008446b2  56                   push esi
// 008446b3  ffd7                 call edi
// 008446b5  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 008446b8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008446bc  8bd1                 mov edx, ecx
// 008446be  2bd0                 sub edx, eax
// 008446c0  83fa0a               cmp edx, 0xa
// 008446c3  7d0b                 jge 0x8446d0
// 008446c5  2bc1                 sub eax, ecx
// 008446c7  83c00a               add eax, 0xa
// 008446ca  50                   push eax
// 008446cb  6a00                 push 0
// 008446cd  56                   push esi
// 008446ce  ffd7                 call edi
// 008446d0  8b442410             mov eax, dword ptr [esp + 0x10]
// 008446d4  2b06                 sub eax, dword ptr [esi]
// 008446d6  83f80a               cmp eax, 0xa
// 008446d9  7d09                 jge 0x8446e4
// 008446db  6a00                 push 0
// 008446dd  83c0f6               add eax, -0xa
// 008446e0  50                   push eax
// 008446e1  56                   push esi
// 008446e2  ffd7                 call edi
// 008446e4  8b4e08               mov ecx, dword ptr [esi + 8]
// 008446e7  8b442408             mov eax, dword ptr [esp + 8]
// 008446eb  8bd1                 mov edx, ecx
// 008446ed  2bd0                 sub edx, eax
// 008446ef  83fa0a               cmp edx, 0xa
// 008446f2  7d0b                 jge 0x8446ff
// 008446f4  2bc1                 sub eax, ecx
// 008446f6  6a00                 push 0
// 008446f8  83c00a               add eax, 0xa
// 008446fb  50                   push eax
// 008446fc  56                   push esi
// 008446fd  ffd7                 call edi
// 008446ff  5f                   pop edi
// 00844700  5e                   pop esi
// 00844701  83c410               add esp, 0x10
// 00844704  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPDockContext.cpp (function ?EnsureVisible@CXTPDockContext@@AAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockContext.cpp
