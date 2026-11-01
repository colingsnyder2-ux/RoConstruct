// from server: 100% by auto
// roc 2007-03 00685de0  unit: seg_00680000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00685de0
//
// 00685de0  8b542404             mov edx, dword ptr [esp + 4]
// 00685de4  85d2                 test edx, edx
// 00685de6  7423                 je 0x685e0b
// 00685de8  83791000             cmp dword ptr [ecx + 0x10], 0
// 00685dec  741d                 je 0x685e0b
// 00685dee  8b442408             mov eax, dword ptr [esp + 8]
// 00685df2  50                   push eax
// 00685df3  c70028000000         mov dword ptr [eax], 0x28
// 00685df9  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00685dfc  52                   push edx
// 00685dfd  ffd0                 call eax
// 00685dff  85c0                 test eax, eax
// 00685e01  7408                 je 0x685e0b
// 00685e03  b801000000           mov eax, 1
// 00685e08  c20800               ret 8
// 00685e0b  33c0                 xor eax, eax
// 00685e0d  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetMonitorInfoA@CXTPMultiMonitor@@AAEHPAUXTP_HMONITOR__@1@PAUXTP_MONITORINFO@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
