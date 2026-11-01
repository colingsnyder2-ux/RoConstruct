// from server: 100% by auto
// roc 2007-03 0045b1f0  unit: seg_00450000  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0045b1f0
//
// 0045b1f0  8b442404             mov eax, dword ptr [esp + 4]
// 0045b1f4  8b5004               mov edx, dword ptr [eax + 4]
// 0045b1f7  56                   push esi
// 0045b1f8  8b30                 mov esi, dword ptr [eax]
// 0045b1fa  57                   push edi
// 0045b1fb  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0045b1ff  57                   push edi
// 0045b200  8b780c               mov edi, dword ptr [eax + 0xc]
// 0045b203  8b4008               mov eax, dword ptr [eax + 8]
// 0045b206  2bfa                 sub edi, edx
// 0045b208  57                   push edi
// 0045b209  2bc6                 sub eax, esi
// 0045b20b  50                   push eax
// 0045b20c  52                   push edx
// 0045b20d  56                   push esi
// 0045b20e  e8a9321c00           call 0x61e4bc
// 0045b213  5f                   pop edi
// 0045b214  5e                   pop esi
// 0045b215  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\ctlppg.cpp (function ?MoveWindow@CWnd@@QAEXPBUtagRECT@@H@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/ctlppg.cpp
