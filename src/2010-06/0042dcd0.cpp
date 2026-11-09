// from server: 100% by auto
// roc 2010-06 0042dcd0  unit: VCFrameWnd::?$CXTPCommandBarsSiteBase  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0042dcd0
//
// 0042dcd0  53                   push ebx
// 0042dcd1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0042dcd5  55                   push ebp
// 0042dcd6  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0042dcda  56                   push esi
// 0042dcdb  8bf1                 mov esi, ecx
// 0042dcdd  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0042dce3  57                   push edi
// 0042dce4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0042dce8  85c9                 test ecx, ecx
// 0042dcea  741d                 je 0x42dd09
// 0042dcec  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042dcf0  57                   push edi
// 0042dcf1  53                   push ebx
// 0042dcf2  55                   push ebp
// 0042dcf3  50                   push eax
// 0042dcf4  e897c63900           call 0x7ca390
// 0042dcf9  85c0                 test eax, eax
// 0042dcfb  740c                 je 0x42dd09
// 0042dcfd  5f                   pop edi
// 0042dcfe  5e                   pop esi
// 0042dcff  5d                   pop ebp
// 0042dd00  b801000000           mov eax, 1
// 0042dd05  5b                   pop ebx
// 0042dd06  c21000               ret 0x10
// 0042dd09  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042dd0d  57                   push edi
// 0042dd0e  53                   push ebx
// 0042dd0f  55                   push ebp
// 0042dd10  51                   push ecx
// 0042dd11  8bce                 mov ecx, esi
// 0042dd13  e8029e3700           call 0x7a7b1a
// 0042dd18  5f                   pop edi
// 0042dd19  5e                   pop esi
// 0042dd1a  5d                   pop ebp
// 0042dd1b  5b                   pop ebx
// 0042dd1c  c21000               ret 0x10
// library xtp-13.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnWndMsg@?$CXTPCommandBarsSiteBase@VCFrameWnd@@@@MAEHIIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPFrameWnd.cpp
