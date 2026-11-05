// from server: 100% by auto
// roc 2010-06 0086dc50  unit: RBX::GuiTarget  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0086dc50
//
// 0086dc50  8b442404             mov eax, dword ptr [esp + 4]
// 0086dc54  33c9                 xor ecx, ecx
// 0086dc56  8908                 mov dword ptr [eax], ecx
// 0086dc58  894804               mov dword ptr [eax + 4], ecx
// 0086dc5b  894808               mov dword ptr [eax + 8], ecx
// 0086dc5e  89480c               mov dword ptr [eax + 0xc], ecx
// 0086dc61  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPanePaintManager.cpp (function ?GetCaptionGripperRect@CXTPDockingPanePaintManager@@UAE?AVCRect@@PBVCXTPDockingPaneTabbedContainer@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPanePaintManager.cpp
