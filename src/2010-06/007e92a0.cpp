// from server: 100% by auto
// roc 2010-06 007e92a0  unit: VCMDIFrameWnd::?$CXTPFrameWndBase  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e92a0
//
// 007e92a0  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 007e92a3  8b442404             mov eax, dword ptr [esp + 4]
// 007e92a7  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007e92aa  8910                 mov dword ptr [eax], edx
// 007e92ac  894804               mov dword ptr [eax + 4], ecx
// 007e92af  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPDockState.cpp (function ?GetScreenSize@CXTPDockState@@AAE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPDockState.cpp
