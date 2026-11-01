// from server: 100% by auto
// roc 2007-03 006b5170  unit: seg_006b0000  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006b5170
//
// 006b5170  83ec10               sub esp, 0x10
// 006b5173  56                   push esi
// 006b5174  8d442404             lea eax, [esp + 4]
// 006b5178  57                   push edi
// 006b5179  50                   push eax
// 006b517a  e8711bfdff           call 0x686cf0
// 006b517f  8bc8                 mov ecx, eax
// 006b5181  e83a17fdff           call 0x6868c0
// 006b5186  8b442414             mov eax, dword ptr [esp + 0x14]
// 006b518a  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 006b518e  2b4604               sub eax, dword ptr [esi + 4]
// 006b5191  8b3d58ed7700         mov edi, dword ptr [0x77ed58]
// 006b5197  83f80a               cmp eax, 0xa
// 006b519a  7d09                 jge 0x6b51a5
// 006b519c  83c0f6               add eax, -0xa
// 006b519f  50                   push eax
// 006b51a0  6a00                 push 0
// 006b51a2  56                   push esi
// 006b51a3  ffd7                 call edi
// 006b51a5  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 006b51a8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006b51ac  8bd1                 mov edx, ecx
// 006b51ae  2bd0                 sub edx, eax
// 006b51b0  83fa0a               cmp edx, 0xa
// 006b51b3  7d0b                 jge 0x6b51c0
// 006b51b5  2bc1                 sub eax, ecx
// 006b51b7  83c00a               add eax, 0xa
// 006b51ba  50                   push eax
// 006b51bb  6a00                 push 0
// 006b51bd  56                   push esi
// 006b51be  ffd7                 call edi
// 006b51c0  8b442410             mov eax, dword ptr [esp + 0x10]
// 006b51c4  2b06                 sub eax, dword ptr [esi]
// 006b51c6  83f80a               cmp eax, 0xa
// 006b51c9  7d09                 jge 0x6b51d4
// 006b51cb  6a00                 push 0
// 006b51cd  83c0f6               add eax, -0xa
// 006b51d0  50                   push eax
// 006b51d1  56                   push esi
// 006b51d2  ffd7                 call edi
// 006b51d4  8b4e08               mov ecx, dword ptr [esi + 8]
// 006b51d7  8b442408             mov eax, dword ptr [esp + 8]
// 006b51db  8bd1                 mov edx, ecx
// 006b51dd  2bd0                 sub edx, eax
// 006b51df  83fa0a               cmp edx, 0xa
// 006b51e2  7d0b                 jge 0x6b51ef
// 006b51e4  2bc1                 sub eax, ecx
// 006b51e6  6a00                 push 0
// 006b51e8  83c00a               add eax, 0xa
// 006b51eb  50                   push eax
// 006b51ec  56                   push esi
// 006b51ed  ffd7                 call edi
// 006b51ef  5f                   pop edi
// 006b51f0  5e                   pop esi
// 006b51f1  83c410               add esp, 0x10
// 006b51f4  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockContext.cpp (function ?EnsureVisible@CXTPDockContext@@AAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockContext.cpp
