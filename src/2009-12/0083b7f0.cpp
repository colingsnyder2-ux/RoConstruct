// from server: 100% by auto
// roc 2009-12 0083b7f0  unit: CXTPToolBar::CControlButtonExpand  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083b7f0
//
// 0083b7f0  8b542404             mov edx, dword ptr [esp + 4]
// 0083b7f4  85d2                 test edx, edx
// 0083b7f6  7423                 je 0x83b81b
// 0083b7f8  83791000             cmp dword ptr [ecx + 0x10], 0
// 0083b7fc  741d                 je 0x83b81b
// 0083b7fe  8b442408             mov eax, dword ptr [esp + 8]
// 0083b802  50                   push eax
// 0083b803  c70028000000         mov dword ptr [eax], 0x28
// 0083b809  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0083b80c  52                   push edx
// 0083b80d  ffd0                 call eax
// 0083b80f  85c0                 test eax, eax
// 0083b811  7408                 je 0x83b81b
// 0083b813  b801000000           mov eax, 1
// 0083b818  c20800               ret 8
// 0083b81b  33c0                 xor eax, eax
// 0083b81d  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetMonitorInfoA@CXTPMultiMonitor@@AAEHPAUXTP_HMONITOR__@1@PAUXTP_MONITORINFO@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
