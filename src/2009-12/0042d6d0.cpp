// from server: 100% by auto
// roc 2009-12 0042d6d0  unit: VCFrameWnd::?$CXTPCommandBarsSiteBase  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0042d6d0
//
// 0042d6d0  53                   push ebx
// 0042d6d1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0042d6d5  55                   push ebp
// 0042d6d6  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0042d6da  56                   push esi
// 0042d6db  8bf1                 mov esi, ecx
// 0042d6dd  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0042d6e3  57                   push edi
// 0042d6e4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0042d6e8  85c9                 test ecx, ecx
// 0042d6ea  741d                 je 0x42d709
// 0042d6ec  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042d6f0  57                   push edi
// 0042d6f1  53                   push ebx
// 0042d6f2  55                   push ebp
// 0042d6f3  50                   push eax
// 0042d6f4  e8c78b3e00           call 0x8162c0
// 0042d6f9  85c0                 test eax, eax
// 0042d6fb  740c                 je 0x42d709
// 0042d6fd  5f                   pop edi
// 0042d6fe  5e                   pop esi
// 0042d6ff  5d                   pop ebp
// 0042d700  b801000000           mov eax, 1
// 0042d705  5b                   pop ebx
// 0042d706  c21000               ret 0x10
// 0042d709  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042d70d  57                   push edi
// 0042d70e  53                   push ebx
// 0042d70f  55                   push ebp
// 0042d710  51                   push ecx
// 0042d711  8bce                 mov ecx, esi
// 0042d713  e8c2623c00           call 0x7f39da
// 0042d718  5f                   pop edi
// 0042d719  5e                   pop esi
// 0042d71a  5d                   pop ebp
// 0042d71b  5b                   pop ebx
// 0042d71c  c21000               ret 0x10
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnWndMsg@?$CXTPCommandBarsSiteBase@VCFrameWnd@@@@MAEHIIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
