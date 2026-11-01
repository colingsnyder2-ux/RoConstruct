// from server: 100% by auto
// roc 2009-12 00835080  unit: CXTPMDIFrameWnd  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00835080
//
// 00835080  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 00835083  8b442404             mov eax, dword ptr [esp + 4]
// 00835087  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0083508a  8910                 mov dword ptr [eax], edx
// 0083508c  894804               mov dword ptr [eax + 4], ecx
// 0083508f  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ?GetScreenSize@CXTPDockState@@AAE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp
