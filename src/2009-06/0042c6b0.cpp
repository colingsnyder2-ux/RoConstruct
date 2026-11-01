// from server: 100% by auto
// roc 2009-06 0042c6b0  unit: VCFrameWnd::?$CXTPCommandBarsSiteBase  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042c6b0
//
// 0042c6b0  53                   push ebx
// 0042c6b1  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0042c6b5  55                   push ebp
// 0042c6b6  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0042c6ba  56                   push esi
// 0042c6bb  8bf1                 mov esi, ecx
// 0042c6bd  8b8ee8000000         mov ecx, dword ptr [esi + 0xe8]
// 0042c6c3  57                   push edi
// 0042c6c4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0042c6c8  85c9                 test ecx, ecx
// 0042c6ca  741d                 je 0x42c6e9
// 0042c6cc  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042c6d0  57                   push edi
// 0042c6d1  53                   push ebx
// 0042c6d2  55                   push ebp
// 0042c6d3  50                   push eax
// 0042c6d4  e837ef2f00           call 0x72b610
// 0042c6d9  85c0                 test eax, eax
// 0042c6db  740c                 je 0x42c6e9
// 0042c6dd  5f                   pop edi
// 0042c6de  5e                   pop esi
// 0042c6df  5d                   pop ebp
// 0042c6e0  b801000000           mov eax, 1
// 0042c6e5  5b                   pop ebx
// 0042c6e6  c21000               ret 0x10
// 0042c6e9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0042c6ed  57                   push edi
// 0042c6ee  53                   push ebx
// 0042c6ef  55                   push ebp
// 0042c6f0  51                   push ecx
// 0042c6f1  8bce                 mov ecx, esi
// 0042c6f3  e8bac42e00           call 0x718bb2
// 0042c6f8  5f                   pop edi
// 0042c6f9  5e                   pop esi
// 0042c6fa  5d                   pop ebp
// 0042c6fb  5b                   pop ebx
// 0042c6fc  c21000               ret 0x10
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnWndMsg@?$CXTPCommandBarsSiteBase@VCFrameWnd@@@@MAEHIIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
