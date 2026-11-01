// from server: 100% by auto
// roc 2009-12 0073cb60  unit: RBX::GuiTarget  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0073cb60
//
// 0073cb60  8b442404             mov eax, dword ptr [esp + 4]
// 0073cb64  33c9                 xor ecx, ecx
// 0073cb66  8908                 mov dword ptr [eax], ecx
// 0073cb68  894804               mov dword ptr [eax + 4], ecx
// 0073cb6b  894808               mov dword ptr [eax + 8], ecx
// 0073cb6e  89480c               mov dword ptr [eax + 0xc], ecx
// 0073cb71  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?GetCaptionGripperRect@CXTPDockingPanePaintManager@@UAE?AVCRect@@PBVCXTPDockingPaneTabbedContainer@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
