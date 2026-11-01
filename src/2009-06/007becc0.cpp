// from server: 100% by auto
// roc 2009-06 007becc0  unit: CXTPDockContext  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007becc0
//
// 007becc0  83ec10               sub esp, 0x10
// 007becc3  56                   push esi
// 007becc4  8d442404             lea eax, [esp + 4]
// 007becc8  57                   push edi
// 007becc9  50                   push eax
// 007becca  e8d12cfaff           call 0x7619a0
// 007beccf  8bc8                 mov ecx, eax
// 007becd1  e89a28faff           call 0x761570
// 007becd6  8b442414             mov eax, dword ptr [esp + 0x14]
// 007becda  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 007becde  2b4604               sub eax, dword ptr [esi + 4]
// 007bece1  8b3df8ed8900         mov edi, dword ptr [0x89edf8]
// 007bece7  83f80a               cmp eax, 0xa
// 007becea  7d09                 jge 0x7becf5
// 007becec  83c0f6               add eax, -0xa
// 007becef  50                   push eax
// 007becf0  6a00                 push 0
// 007becf2  56                   push esi
// 007becf3  ffd7                 call edi
// 007becf5  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007becf8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007becfc  8bd1                 mov edx, ecx
// 007becfe  2bd0                 sub edx, eax
// 007bed00  83fa0a               cmp edx, 0xa
// 007bed03  7d0b                 jge 0x7bed10
// 007bed05  2bc1                 sub eax, ecx
// 007bed07  83c00a               add eax, 0xa
// 007bed0a  50                   push eax
// 007bed0b  6a00                 push 0
// 007bed0d  56                   push esi
// 007bed0e  ffd7                 call edi
// 007bed10  8b442410             mov eax, dword ptr [esp + 0x10]
// 007bed14  2b06                 sub eax, dword ptr [esi]
// 007bed16  83f80a               cmp eax, 0xa
// 007bed19  7d09                 jge 0x7bed24
// 007bed1b  6a00                 push 0
// 007bed1d  83c0f6               add eax, -0xa
// 007bed20  50                   push eax
// 007bed21  56                   push esi
// 007bed22  ffd7                 call edi
// 007bed24  8b4e08               mov ecx, dword ptr [esi + 8]
// 007bed27  8b442408             mov eax, dword ptr [esp + 8]
// 007bed2b  8bd1                 mov edx, ecx
// 007bed2d  2bd0                 sub edx, eax
// 007bed2f  83fa0a               cmp edx, 0xa
// 007bed32  7d0b                 jge 0x7bed3f
// 007bed34  2bc1                 sub eax, ecx
// 007bed36  6a00                 push 0
// 007bed38  83c00a               add eax, 0xa
// 007bed3b  50                   push eax
// 007bed3c  56                   push esi
// 007bed3d  ffd7                 call edi
// 007bed3f  5f                   pop edi
// 007bed40  5e                   pop esi
// 007bed41  83c410               add esp, 0x10
// 007bed44  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockContext.cpp (function ?EnsureVisible@CXTPDockContext@@AAEXAAVCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockContext.cpp
