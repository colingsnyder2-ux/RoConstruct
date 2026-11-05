// from server: 100% by auto
// roc 2010-06 007ef940  unit: CXTPToolBar::CControlButtonExpand  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef940
//
// 007ef940  8b542404             mov edx, dword ptr [esp + 4]
// 007ef944  85d2                 test edx, edx
// 007ef946  7423                 je 0x7ef96b
// 007ef948  83791000             cmp dword ptr [ecx + 0x10], 0
// 007ef94c  741d                 je 0x7ef96b
// 007ef94e  8b442408             mov eax, dword ptr [esp + 8]
// 007ef952  50                   push eax
// 007ef953  c70028000000         mov dword ptr [eax], 0x28
// 007ef959  8b4110               mov eax, dword ptr [ecx + 0x10]
// 007ef95c  52                   push edx
// 007ef95d  ffd0                 call eax
// 007ef95f  85c0                 test eax, eax
// 007ef961  7408                 je 0x7ef96b
// 007ef963  b801000000           mov eax, 1
// 007ef968  c20800               ret 8
// 007ef96b  33c0                 xor eax, eax
// 007ef96d  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetMonitorInfoA@CXTPMultiMonitor@@AAEHPAUXTP_HMONITOR__@1@PAUXTP_MONITORINFO@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
