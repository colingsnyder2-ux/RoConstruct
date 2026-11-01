// from server: 100% by auto
// roc 2007-03 006cf090  unit: seg_006c0000  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006cf090
//
// 006cf090  8b442404             mov eax, dword ptr [esp + 4]
// 006cf094  33c9                 xor ecx, ecx
// 006cf096  8908                 mov dword ptr [eax], ecx
// 006cf098  894804               mov dword ptr [eax + 4], ecx
// 006cf09b  894808               mov dword ptr [eax + 8], ecx
// 006cf09e  89480c               mov dword ptr [eax + 0xc], ecx
// 006cf0a1  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?GetCaptionGripperRect@CXTPDockingPanePaintManager@@UAE?AVCRect@@PBVCXTPDockingPaneTabbedContainer@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
