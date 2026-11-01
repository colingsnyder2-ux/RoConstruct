// from server: 100% by auto
// roc 2012-06 0043da40  unit: CMainFrame  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0043da40
//
// 0043da40  53                   push ebx
// 0043da41  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0043da45  55                   push ebp
// 0043da46  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0043da4a  56                   push esi
// 0043da4b  8b742410             mov esi, dword ptr [esp + 0x10]
// 0043da4f  8d863ddcffff         lea eax, [esi - 0x23c3]
// 0043da55  57                   push edi
// 0043da56  8bf9                 mov edi, ecx
// 0043da58  83f803               cmp eax, 3
// 0043da5b  7731                 ja 0x43da8e
// 0043da5d  8b8fe8000000         mov ecx, dword ptr [edi + 0xe8]
// 0043da63  51                   push ecx
// 0043da64  e80d515400           call 0x982b76
// 0043da69  85c0                 test eax, eax
// 0043da6b  7421                 je 0x43da8e
// 0043da6d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043da71  8b10                 mov edx, dword ptr [eax]
// 0043da73  8b5214               mov edx, dword ptr [edx + 0x14]
// 0043da76  53                   push ebx
// 0043da77  55                   push ebp
// 0043da78  51                   push ecx
// 0043da79  56                   push esi
// 0043da7a  8bc8                 mov ecx, eax
// 0043da7c  ffd2                 call edx
// 0043da7e  85c0                 test eax, eax
// 0043da80  740c                 je 0x43da8e
// 0043da82  5f                   pop edi
// 0043da83  5e                   pop esi
// 0043da84  5d                   pop ebp
// 0043da85  b801000000           mov eax, 1
// 0043da8a  5b                   pop ebx
// 0043da8b  c21000               ret 0x10
// 0043da8e  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043da92  53                   push ebx
// 0043da93  55                   push ebp
// 0043da94  50                   push eax
// 0043da95  56                   push esi
// 0043da96  8bcf                 mov ecx, edi
// 0043da98  e867505400           call 0x982b04
// 0043da9d  5f                   pop edi
// 0043da9e  5e                   pop esi
// 0043da9f  5d                   pop ebp
// 0043daa0  5b                   pop ebx
// 0043daa1  c21000               ret 0x10
// library xtp-15.2.1-shared-mfc/Source\CommandBars\XTPFrameWnd.cpp (function ?OnCmdMsg@CXTPMDIFrameWnd@@UAEHIHPAXPAUAFX_CMDHANDLERINFO@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/CommandBars/XTPFrameWnd.cpp
