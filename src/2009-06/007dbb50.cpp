// from server: 100% by auto
// roc 2009-06 007dbb50  unit: CXTPDockingPanePaintManager  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007dbb50
//
// 007dbb50  8b442404             mov eax, dword ptr [esp + 4]
// 007dbb54  33c9                 xor ecx, ecx
// 007dbb56  8908                 mov dword ptr [eax], ecx
// 007dbb58  894804               mov dword ptr [eax + 4], ecx
// 007dbb5b  894808               mov dword ptr [eax + 8], ecx
// 007dbb5e  89480c               mov dword ptr [eax + 0xc], ecx
// 007dbb61  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?GetCaptionGripperRect@CXTPDockingPanePaintManager@@UAE?AVCRect@@PBVCXTPDockingPaneTabbedContainer@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
