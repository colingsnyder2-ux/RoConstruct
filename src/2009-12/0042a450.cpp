// from server: 100% by auto
// roc 2009-12 0042a450  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042a450
//
// 0042a450  53                   push ebx
// 0042a451  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0042a455  55                   push ebp
// 0042a456  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0042a45a  56                   push esi
// 0042a45b  8bf1                 mov esi, ecx
// 0042a45d  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0042a463  57                   push edi
// 0042a464  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0042a468  85c9                 test ecx, ecx
// 0042a46a  741d                 je 0x42a489
// 0042a46c  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042a470  57                   push edi
// 0042a471  53                   push ebx
// 0042a472  55                   push ebp
// 0042a473  50                   push eax
// 0042a474  e847be3e00           call 0x8162c0
// 0042a479  85c0                 test eax, eax
// 0042a47b  740c                 je 0x42a489
// 0042a47d  5f                   pop edi
// 0042a47e  5e                   pop esi
// 0042a47f  5d                   pop ebp
// 0042a480  b801000000           mov eax, 1
// 0042a485  5b                   pop ebx
// 0042a486  c21000               ret 0x10
// 0042a489  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042a48d  57                   push edi
// 0042a48e  53                   push ebx
// 0042a48f  55                   push ebp
// 0042a490  51                   push ecx
// 0042a491  8bce                 mov ecx, esi
// 0042a493  e842953c00           call 0x7f39da
// 0042a498  5f                   pop edi
// 0042a499  5e                   pop esi
// 0042a49a  5d                   pop ebp
// 0042a49b  5b                   pop ebx
// 0042a49c  c21000               ret 0x10
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnWndMsg@?$CXTPCommandBarsSiteBase@VCMDIFrameWnd@@@@MAEHIIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
