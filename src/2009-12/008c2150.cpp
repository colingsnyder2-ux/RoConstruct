// from server: 100% by auto
// roc 2009-12 008c2150  unit: CXTPImageEditorDlg::CDlgToolBar  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c2150
//
// 008c2150  83ec0c               sub esp, 0xc
// 008c2153  56                   push esi
// 008c2154  8bf1                 mov esi, ecx
// 008c2156  8b4620               mov eax, dword ptr [esi + 0x20]
// 008c2159  89442404             mov dword ptr [esp + 4], eax
// 008c215d  c744240cfeffffff     mov dword ptr [esp + 0xc], 0xfffffffe
// 008c2165  e860450600           call 0x9266ca
// 008c216a  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 008c216d  51                   push ecx
// 008c216e  8944240c             mov dword ptr [esp + 0xc], eax
// 008c2172  ff15bccb9800         call dword ptr [0x98cbbc]
// 008c2178  50                   push eax
// 008c2179  e8ac19f3ff           call 0x7f3b2a
// 008c217e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008c2182  8d542404             lea edx, [esp + 4]
// 008c2186  52                   push edx
// 008c2187  8b5020               mov edx, dword ptr [eax + 0x20]
// 008c218a  51                   push ecx
// 008c218b  6a4e                 push 0x4e
// 008c218d  52                   push edx
// 008c218e  ff15c4cb9800         call dword ptr [0x98cbc4]
// 008c2194  5e                   pop esi
// 008c2195  83c40c               add esp, 0xc
// 008c2198  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnLButtonDown@CXTPImageEditorPicker@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
