// from server: 100% by Yeetserama
// roc 2007-08 0041d5f0  unit: CInsertObjectDialog  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041d5f0
//
// 0041d5f0  56                   push esi
// 0041d5f1  8bf1                 mov esi, ecx
// 0041d5f3  8d4e74               lea ecx, [esi + 0x74]
// 0041d5f6  c706847b7800         mov dword ptr [esi], 0x787b84
// 0041d5fc  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0041d602  8bce                 mov ecx, esi
// 0041d604  e8092e2100           call 0x630412
// 0041d609  f644240801           test byte ptr [esp + 8], 1
// 0041d60e  7409                 je 0x41d619
// 0041d610  56                   push esi
// 0041d611  e84c262100           call 0x62fc62
// 0041d616  83c404               add esp, 4
// 0041d619  8bc6                 mov eax, esi
// 0041d61b  5e                   pop esi
// 0041d61c  c20400               ret 4
// copied from an identical function in another client (function ??_GCXTPPromptDlg@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/ReportControl/XTPReportControl.cpp