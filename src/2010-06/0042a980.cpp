// from server: 100% by auto
// roc 2010-06 0042a980  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042a980
//
// 0042a980  53                   push ebx
// 0042a981  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0042a985  55                   push ebp
// 0042a986  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0042a98a  56                   push esi
// 0042a98b  8bf1                 mov esi, ecx
// 0042a98d  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 0042a993  57                   push edi
// 0042a994  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0042a998  85c9                 test ecx, ecx
// 0042a99a  741d                 je 0x42a9b9
// 0042a99c  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042a9a0  57                   push edi
// 0042a9a1  53                   push ebx
// 0042a9a2  55                   push ebp
// 0042a9a3  50                   push eax
// 0042a9a4  e8e7f93900           call 0x7ca390
// 0042a9a9  85c0                 test eax, eax
// 0042a9ab  740c                 je 0x42a9b9
// 0042a9ad  5f                   pop edi
// 0042a9ae  5e                   pop esi
// 0042a9af  5d                   pop ebp
// 0042a9b0  b801000000           mov eax, 1
// 0042a9b5  5b                   pop ebx
// 0042a9b6  c21000               ret 0x10
// 0042a9b9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042a9bd  57                   push edi
// 0042a9be  53                   push ebx
// 0042a9bf  55                   push ebp
// 0042a9c0  51                   push ecx
// 0042a9c1  8bce                 mov ecx, esi
// 0042a9c3  e852d13700           call 0x7a7b1a
// 0042a9c8  5f                   pop edi
// 0042a9c9  5e                   pop esi
// 0042a9ca  5d                   pop ebp
// 0042a9cb  5b                   pop ebx
// 0042a9cc  c21000               ret 0x10
// library xtp-13.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnWndMsg@?$CXTPCommandBarsSiteBase@VCMDIFrameWnd@@@@MAEHIIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPFrameWnd.cpp
