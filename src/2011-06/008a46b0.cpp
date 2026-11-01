// from server: 100% by auto
// roc 2011-06 008a46b0  unit: CXTPMenuBar::CControlMDIButton  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a46b0
//
// 008a46b0  8b442404             mov eax, dword ptr [esp + 4]
// 008a46b4  56                   push esi
// 008a46b5  57                   push edi
// 008a46b6  50                   push eax
// 008a46b7  e86c5cf6ff           call 0x80a328
// 008a46bc  50                   push eax
// 008a46bd  e864801200           call 0x9cc726
// 008a46c2  50                   push eax
// 008a46c3  e8745df6ff           call 0x80a43c
// 008a46c8  8bf0                 mov esi, eax
// 008a46ca  83c408               add esp, 8
// 008a46cd  85f6                 test esi, esi
// 008a46cf  7417                 je 0x8a46e8
// 008a46d1  8bce                 mov ecx, esi
// 008a46d3  e82e5df6ff           call 0x80a406
// 008a46d8  85c0                 test eax, eax
// 008a46da  740c                 je 0x8a46e8
// 008a46dc  8bce                 mov ecx, esi
// 008a46de  e8235df6ff           call 0x80a406
// 008a46e3  8b4054               mov eax, dword ptr [eax + 0x54]
// 008a46e6  eb02                 jmp 0x8a46ea
// 008a46e8  33c0                 xor eax, eax
// 008a46ea  50                   push eax
// 008a46eb  e83a821200           call 0x9cc92a
// 008a46f0  50                   push eax
// 008a46f1  e8465df6ff           call 0x80a43c
// 008a46f6  8bf8                 mov edi, eax
// 008a46f8  83c408               add esp, 8
// 008a46fb  85ff                 test edi, edi
// 008a46fd  7434                 je 0x8a4733
// 008a46ff  85f6                 test esi, esi
// 008a4701  7430                 je 0x8a4733
// 008a4703  53                   push ebx
// 008a4704  8b1f                 mov ebx, dword ptr [edi]
// 008a4706  8bce                 mov ecx, esi
// 008a4708  e8f95cf6ff           call 0x80a406
// 008a470d  8b93b8000000         mov edx, dword ptr [ebx + 0xb8]
// 008a4713  50                   push eax
// 008a4714  8bcf                 mov ecx, edi
// 008a4716  ffd2                 call edx
// 008a4718  50                   push eax
// 008a4719  e81a861200           call 0x9ccd38
// 008a471e  50                   push eax
// 008a471f  e8185df6ff           call 0x80a43c
// 008a4724  83c408               add esp, 8
// 008a4727  f7d8                 neg eax
// 008a4729  5b                   pop ebx
// 008a472a  1bc0                 sbb eax, eax
// 008a472c  5f                   pop edi
// 008a472d  f7d8                 neg eax
// 008a472f  5e                   pop esi
// 008a4730  c20400               ret 4
// 008a4733  5f                   pop edi
// 008a4734  33c0                 xor eax, eax
// 008a4736  5e                   pop esi
// 008a4737  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPMenuBar.cpp (function ?IsOleDocumentActive@CXTPMenuBar@@ABEHPAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPMenuBar.cpp
