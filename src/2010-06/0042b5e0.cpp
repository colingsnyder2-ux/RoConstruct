// from server: 100% by auto
// roc 2010-06 0042b5e0  unit: CMainFrame  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042b5e0
//
// 0042b5e0  53                   push ebx
// 0042b5e1  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0042b5e5  55                   push ebp
// 0042b5e6  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0042b5ea  56                   push esi
// 0042b5eb  8b742410             mov esi, dword ptr [esp + 0x10]
// 0042b5ef  8d863ddcffff         lea eax, [esi - 0x23c3]
// 0042b5f5  57                   push edi
// 0042b5f6  8bf9                 mov edi, ecx
// 0042b5f8  83f803               cmp eax, 3
// 0042b5fb  7731                 ja 0x42b62e
// 0042b5fd  8b8fe8000000         mov ecx, dword ptr [edi + 0xe8]
// 0042b603  51                   push ecx
// 0042b604  e817ce3700           call 0x7a8420
// 0042b609  85c0                 test eax, eax
// 0042b60b  7421                 je 0x42b62e
// 0042b60d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042b611  8b10                 mov edx, dword ptr [eax]
// 0042b613  8b5214               mov edx, dword ptr [edx + 0x14]
// 0042b616  53                   push ebx
// 0042b617  55                   push ebp
// 0042b618  51                   push ecx
// 0042b619  56                   push esi
// 0042b61a  8bc8                 mov ecx, eax
// 0042b61c  ffd2                 call edx
// 0042b61e  85c0                 test eax, eax
// 0042b620  740c                 je 0x42b62e
// 0042b622  5f                   pop edi
// 0042b623  5e                   pop esi
// 0042b624  5d                   pop ebp
// 0042b625  b801000000           mov eax, 1
// 0042b62a  5b                   pop ebx
// 0042b62b  c21000               ret 0x10
// 0042b62e  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042b632  53                   push ebx
// 0042b633  55                   push ebp
// 0042b634  50                   push eax
// 0042b635  56                   push esi
// 0042b636  8bcf                 mov ecx, edi
// 0042b638  e877cd3700           call 0x7a83b4
// 0042b63d  5f                   pop edi
// 0042b63e  5e                   pop esi
// 0042b63f  5d                   pop ebp
// 0042b640  5b                   pop ebx
// 0042b641  c21000               ret 0x10
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPFrameWnd.cpp (function ?OnCmdMsg@CXTPMDIFrameWnd@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPFrameWnd.cpp
