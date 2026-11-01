// from server: 100% by auto
// roc 2009-06 00760a20  unit: CXTPToolBar::CControlButtonExpand  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00760a20
//
// 00760a20  8b542404             mov edx, dword ptr [esp + 4]
// 00760a24  85d2                 test edx, edx
// 00760a26  7423                 je 0x760a4b
// 00760a28  83791000             cmp dword ptr [ecx + 0x10], 0
// 00760a2c  741d                 je 0x760a4b
// 00760a2e  8b442408             mov eax, dword ptr [esp + 8]
// 00760a32  50                   push eax
// 00760a33  c70028000000         mov dword ptr [eax], 0x28
// 00760a39  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00760a3c  52                   push edx
// 00760a3d  ffd0                 call eax
// 00760a3f  85c0                 test eax, eax
// 00760a41  7408                 je 0x760a4b
// 00760a43  b801000000           mov eax, 1
// 00760a48  c20800               ret 8
// 00760a4b  33c0                 xor eax, eax
// 00760a4d  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetMonitorInfoA@CXTPMultiMonitor@@AAEHPAUXTP_HMONITOR__@1@PAUXTP_MONITORINFO@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
