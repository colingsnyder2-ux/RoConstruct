// from server: 100% by auto
// roc 2007-03 00710300  unit: seg_00710000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00710300
//
// 00710300  8b442404             mov eax, dword ptr [esp + 4]
// 00710304  8b511c               mov edx, dword ptr [ecx + 0x1c]
// 00710307  8910                 mov dword ptr [eax], edx
// 00710309  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0071030c  895004               mov dword ptr [eax + 4], edx
// 0071030f  8b5124               mov edx, dword ptr [ecx + 0x24]
// 00710312  8b4928               mov ecx, dword ptr [ecx + 0x28]
// 00710315  895008               mov dword ptr [eax + 8], edx
// 00710318  89480c               mov dword ptr [eax + 0xc], ecx
// 0071031b  c20400               ret 4
// library xtp-15.2.1/Source\Controls\CoreTree\XTPCoreTreeItem.cpp (function ?GetRect@CXTPCoreTreeItem@@QBE?AVCRect@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/CoreTree/XTPCoreTreeItem.cpp
