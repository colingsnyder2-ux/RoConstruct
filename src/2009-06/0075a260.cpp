// from server: 100% by auto
// roc 2009-06 0075a260  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0075a260
//
// 0075a260  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 0075a263  8b442404             mov eax, dword ptr [esp + 4]
// 0075a267  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 0075a26a  8910                 mov dword ptr [eax], edx
// 0075a26c  894804               mov dword ptr [eax + 4], ecx
// 0075a26f  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ?GetScreenSize@CXTPDockState@@AAE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp
