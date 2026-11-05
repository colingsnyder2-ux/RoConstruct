// from server: 100% by auto
// roc 2010-06 00876370  unit: CXTPImageEditorDlg::CDlgToolBar  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00876370
//
// 00876370  83ec0c               sub esp, 0xc
// 00876373  56                   push esi
// 00876374  8bf1                 mov esi, ecx
// 00876376  8b4620               mov eax, dword ptr [esi + 0x20]
// 00876379  89442404             mov dword ptr [esp + 4], eax
// 0087637d  c744240cfeffffff     mov dword ptr [esp + 0xc], 0xfffffffe
// 00876385  e87c6c1000           call 0x97d006
// 0087638a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0087638d  51                   push ecx
// 0087638e  8944240c             mov dword ptr [esp + 0xc], eax
// 00876392  ff154cba9e00         call dword ptr [0x9eba4c]
// 00876398  50                   push eax
// 00876399  e8cc18f3ff           call 0x7a7c6a
// 0087639e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008763a2  8d542404             lea edx, [esp + 4]
// 008763a6  52                   push edx
// 008763a7  8b5020               mov edx, dword ptr [eax + 0x20]
// 008763aa  51                   push ecx
// 008763ab  6a4e                 push 0x4e
// 008763ad  52                   push edx
// 008763ae  ff1554ba9e00         call dword ptr [0x9eba54]
// 008763b4  5e                   pop esi
// 008763b5  83c40c               add esp, 0xc
// 008763b8  c20c00               ret 0xc
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnLButtonDown@CXTPImageEditorPicker@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
