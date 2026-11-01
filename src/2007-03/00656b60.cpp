// from server: 100% by auto
// roc 2007-03 00656b60  unit: seg_00650000  size: 18 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00656b60
//
// 00656b60  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 00656b63  8b442404             mov eax, dword ptr [esp + 4]
// 00656b67  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 00656b6a  8910                 mov dword ptr [eax], edx
// 00656b6c  894804               mov dword ptr [eax + 4], ecx
// 00656b6f  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPDockState.cpp (function ?GetScreenSize@CXTPDockState@@AAE?AVCSize@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockState.cpp
