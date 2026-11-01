// from server: 100% by auto
// roc 2011-06 00436cc0  unit: CMainFrame  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00436cc0
//
// 00436cc0  53                   push ebx
// 00436cc1  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00436cc5  55                   push ebp
// 00436cc6  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00436cca  56                   push esi
// 00436ccb  8b742410             mov esi, dword ptr [esp + 0x10]
// 00436ccf  8d863ddcffff         lea eax, [esi - 0x23c3]
// 00436cd5  57                   push edi
// 00436cd6  8bf9                 mov edi, ecx
// 00436cd8  83f803               cmp eax, 3
// 00436cdb  7731                 ja 0x436d0e
// 00436cdd  8b8fe8000000         mov ecx, dword ptr [edi + 0xe8]
// 00436ce3  51                   push ecx
// 00436ce4  e8fb3d3d00           call 0x80aae4
// 00436ce9  85c0                 test eax, eax
// 00436ceb  7421                 je 0x436d0e
// 00436ced  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00436cf1  8b10                 mov edx, dword ptr [eax]
// 00436cf3  8b5214               mov edx, dword ptr [edx + 0x14]
// 00436cf6  53                   push ebx
// 00436cf7  55                   push ebp
// 00436cf8  51                   push ecx
// 00436cf9  56                   push esi
// 00436cfa  8bc8                 mov ecx, eax
// 00436cfc  ffd2                 call edx
// 00436cfe  85c0                 test eax, eax
// 00436d00  740c                 je 0x436d0e
// 00436d02  5f                   pop edi
// 00436d03  5e                   pop esi
// 00436d04  5d                   pop ebp
// 00436d05  b801000000           mov eax, 1
// 00436d0a  5b                   pop ebx
// 00436d0b  c21000               ret 0x10
// 00436d0e  8b442418             mov eax, dword ptr [esp + 0x18]
// 00436d12  53                   push ebx
// 00436d13  55                   push ebp
// 00436d14  50                   push eax
// 00436d15  56                   push esi
// 00436d16  8bcf                 mov ecx, edi
// 00436d18  e8613d3d00           call 0x80aa7e
// 00436d1d  5f                   pop edi
// 00436d1e  5e                   pop esi
// 00436d1f  5d                   pop ebp
// 00436d20  5b                   pop ebx
// 00436d21  c21000               ret 0x10
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPFrameWnd.cpp (function ?OnCmdMsg@CXTPMDIFrameWnd@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPFrameWnd.cpp
