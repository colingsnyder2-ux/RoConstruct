// from server: 100% by auto
// roc 2009-06 00429690  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00429690
//
// 00429690  53                   push ebx
// 00429691  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 00429695  55                   push ebp
// 00429696  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 0042969a  56                   push esi
// 0042969b  8bf1                 mov esi, ecx
// 0042969d  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 004296a3  57                   push edi
// 004296a4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 004296a8  85c9                 test ecx, ecx
// 004296aa  741d                 je 0x4296c9
// 004296ac  8b442414             mov eax, dword ptr [esp + 0x14]
// 004296b0  57                   push edi
// 004296b1  53                   push ebx
// 004296b2  55                   push ebp
// 004296b3  50                   push eax
// 004296b4  e8571f3000           call 0x72b610
// 004296b9  85c0                 test eax, eax
// 004296bb  740c                 je 0x4296c9
// 004296bd  5f                   pop edi
// 004296be  5e                   pop esi
// 004296bf  5d                   pop ebp
// 004296c0  b801000000           mov eax, 1
// 004296c5  5b                   pop ebx
// 004296c6  c21000               ret 0x10
// 004296c9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004296cd  57                   push edi
// 004296ce  53                   push ebx
// 004296cf  55                   push ebp
// 004296d0  51                   push ecx
// 004296d1  8bce                 mov ecx, esi
// 004296d3  e8daf42e00           call 0x718bb2
// 004296d8  5f                   pop edi
// 004296d9  5e                   pop esi
// 004296da  5d                   pop ebp
// 004296db  5b                   pop ebx
// 004296dc  c21000               ret 0x10
// library xtp-15.2.1/Source\CommandBars\XTPFrameWnd.cpp (function ?OnWndMsg@?$CXTPCommandBarsSiteBase@VCMDIFrameWnd@@@@MAEHIIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPFrameWnd.cpp
