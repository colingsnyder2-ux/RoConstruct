// from server: 100% by auto
// roc 2009-06 007db1f0  unit: XTPDockingPanePaintThemes::CXTPDockingPaneWhidbeyTheme::CColorSetVisualStudio2005  size: 244 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007db1f0
//
// 007db1f0  837c241000           cmp dword ptr [esp + 0x10], 0
// 007db1f5  56                   push esi
// 007db1f6  8b742418             mov esi, dword ptr [esp + 0x18]
// 007db1fa  57                   push edi
// 007db1fb  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007db1ff  743c                 je 0x7db23d
// 007db201  8b442414             mov eax, dword ptr [esp + 0x14]
// 007db205  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007db209  56                   push esi
// 007db20a  56                   push esi
// 007db20b  6a09                 push 9
// 007db20d  6a09                 push 9
// 007db20f  83c0fb               add eax, -5
// 007db212  83c1fb               add ecx, -5
// 007db215  50                   push eax
// 007db216  51                   push ecx
// 007db217  8bcf                 mov ecx, edi
// 007db219  e8f2140700           call 0x84c710
// 007db21e  8b542414             mov edx, dword ptr [esp + 0x14]
// 007db222  8b442410             mov eax, dword ptr [esp + 0x10]
// 007db226  56                   push esi
// 007db227  6a02                 push 2
// 007db229  6a09                 push 9
// 007db22b  83c2fb               add edx, -5
// 007db22e  52                   push edx
// 007db22f  83c0fb               add eax, -5
// 007db232  50                   push eax
// 007db233  8bcf                 mov ecx, edi
// 007db235  e8f60c0700           call 0x84bf30
// 007db23a  5f                   pop edi
// 007db23b  5e                   pop esi
// 007db23c  c3                   ret 
// 007db23d  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007db241  8b542410             mov edx, dword ptr [esp + 0x10]
// 007db245  53                   push ebx
// 007db246  56                   push esi
// 007db247  56                   push esi
// 007db248  6a06                 push 6
// 007db24a  6a06                 push 6
// 007db24c  83c1fe               add ecx, -2
// 007db24f  51                   push ecx
// 007db250  83c2fc               add edx, -4
// 007db253  52                   push edx
// 007db254  8bcf                 mov ecx, edi
// 007db256  e8b5140700           call 0x84c710
// 007db25b  8b442418             mov eax, dword ptr [esp + 0x18]
// 007db25f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007db263  56                   push esi
// 007db264  6a02                 push 2
// 007db266  6a06                 push 6
// 007db268  83c0fe               add eax, -2
// 007db26b  83c1fc               add ecx, -4
// 007db26e  50                   push eax
// 007db26f  51                   push ecx
// 007db270  8bcf                 mov ecx, edi
// 007db272  e8b90c0700           call 0x84bf30
// 007db277  8b542418             mov edx, dword ptr [esp + 0x18]
// 007db27b  8b442414             mov eax, dword ptr [esp + 0x14]
// 007db27f  56                   push esi
// 007db280  6a02                 push 2
// 007db282  6a06                 push 6
// 007db284  83c2fb               add edx, -5
// 007db287  52                   push edx
// 007db288  83c0fe               add eax, -2
// 007db28b  50                   push eax
// 007db28c  8bcf                 mov ecx, edi
// 007db28e  e89d0c0700           call 0x84bf30
// 007db293  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007db297  8b542414             mov edx, dword ptr [esp + 0x14]
// 007db29b  8b4704               mov eax, dword ptr [edi + 4]
// 007db29e  8b1dd4e08900         mov ebx, dword ptr [0x89e0d4]
// 007db2a4  56                   push esi
// 007db2a5  83c1fd               add ecx, -3
// 007db2a8  51                   push ecx
// 007db2a9  83c2fe               add edx, -2
// 007db2ac  52                   push edx
// 007db2ad  50                   push eax
// 007db2ae  ffd3                 call ebx
// 007db2b0  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007db2b4  8b542414             mov edx, dword ptr [esp + 0x14]
// 007db2b8  56                   push esi
// 007db2b9  6a04                 push 4
// 007db2bb  6a01                 push 1
// 007db2bd  83c1fd               add ecx, -3
// 007db2c0  51                   push ecx
// 007db2c1  83c203               add edx, 3
// 007db2c4  52                   push edx
// 007db2c5  8bcf                 mov ecx, edi
// 007db2c7  e8640c0700           call 0x84bf30
// 007db2cc  8b442418             mov eax, dword ptr [esp + 0x18]
// 007db2d0  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007db2d4  8b5704               mov edx, dword ptr [edi + 4]
// 007db2d7  56                   push esi
// 007db2d8  50                   push eax
// 007db2d9  83c102               add ecx, 2
// 007db2dc  51                   push ecx
// 007db2dd  52                   push edx
// 007db2de  ffd3                 call ebx
// 007db2e0  5b                   pop ebx
// 007db2e1  5f                   pop edi
// 007db2e2  5e                   pop esi
// 007db2e3  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?DrawMaximizeRestoreButton@CXTPDockingPaneCaptionButton@@SAXPAVCDC@@VCPoint@@HK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
