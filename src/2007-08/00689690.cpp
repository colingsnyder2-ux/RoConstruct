// from server: 100% by auto
// roc 2007-08 00689690  unit: CXTPTabClientWnd::CWorkspace  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00689690
//
// 00689690  8b818c000000         mov eax, dword ptr [ecx + 0x8c]
// 00689696  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0068969a  8988bc000000         mov dword ptr [eax + 0xbc], ecx
// 006896a0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPTabClientWnd.cpp (function ?SetAllowReorder@CWorkspace@CXTPTabClientWnd@@MAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPTabClientWnd.cpp
