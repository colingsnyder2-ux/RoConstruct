// from server: 100% by auto
// roc 2010-06 00875760  unit: CXTPImageEditorDlg::CDlgToolBar  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00875760
//
// 00875760  8b442404             mov eax, dword ptr [esp + 4]
// 00875764  83ec10               sub esp, 0x10
// 00875767  53                   push ebx
// 00875768  55                   push ebp
// 00875769  56                   push esi
// 0087576a  57                   push edi
// 0087576b  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0087576f  57                   push edi
// 00875770  8bf1                 mov esi, ecx
// 00875772  50                   push eax
// 00875773  897e64               mov dword ptr [esi + 0x64], edi
// 00875776  e8fb771000           call 0x97cf76
// 0087577b  8b8f600a0000         mov ecx, dword ptr [edi + 0xa60]
// 00875781  894e54               mov dword ptr [esi + 0x54], ecx
// 00875784  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00875787  8b97640a0000         mov edx, dword ptr [edi + 0xa64]
// 0087578d  8d442410             lea eax, [esp + 0x10]
// 00875791  50                   push eax
// 00875792  51                   push ecx
// 00875793  895658               mov dword ptr [esi + 0x58], edx
// 00875796  ff153cbc9e00         call dword ptr [0x9ebc3c]
// 0087579c  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 008757a0  8b442418             mov eax, dword ptr [esp + 0x18]
// 008757a4  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 008757a7  2bc3                 sub eax, ebx
// 008757a9  99                   cdq 
// 008757aa  f7f9                 idiv ecx
// 008757ac  8b7e58               mov edi, dword ptr [esi + 0x58]
// 008757af  6a02                 push 2
// 008757b1  8be8                 mov ebp, eax
// 008757b3  8b442420             mov eax, dword ptr [esp + 0x20]
// 008757b7  2b442418             sub eax, dword ptr [esp + 0x18]
// 008757bb  896e5c               mov dword ptr [esi + 0x5c], ebp
// 008757be  99                   cdq 
// 008757bf  f7ff                 idiv edi
// 008757c1  8b542418             mov edx, dword ptr [esp + 0x18]
// 008757c5  894660               mov dword ptr [esi + 0x60], eax
// 008757c8  8bc5                 mov eax, ebp
// 008757ca  0fafc1               imul eax, ecx
// 008757cd  8b4e60               mov ecx, dword ptr [esi + 0x60]
// 008757d0  0fafcf               imul ecx, edi
// 008757d3  41                   inc ecx
// 008757d4  51                   push ecx
// 008757d5  40                   inc eax
// 008757d6  50                   push eax
// 008757d7  a178c79e00           mov eax, dword ptr [0x9ec778]
// 008757dc  52                   push edx
// 008757dd  53                   push ebx
// 008757de  50                   push eax
// 008757df  8bce                 mov ecx, esi
// 008757e1  e88625f3ff           call 0x7a7d6c
// 008757e6  6a00                 push 0
// 008757e8  ff15aca09e00         call dword ptr [0x9ea0ac]
// 008757ee  50                   push eax
// 008757ef  8d4e68               lea ecx, [esi + 0x68]
// 008757f2  e899751000           call 0x97cd90
// 008757f7  5f                   pop edi
// 008757f8  5e                   pop esi
// 008757f9  5d                   pop ebp
// 008757fa  5b                   pop ebx
// 008757fb  83c410               add esp, 0x10
// 008757fe  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPImageEditor.cpp (function ?Init@CXTPImageEditorPicture@@QAEXIPAVCXTPImageEditorDlg@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPImageEditor.cpp
