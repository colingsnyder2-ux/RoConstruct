// from server: 100% by auto
// roc 2007-03 0071e830  unit: seg_00710000  size: 39 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071e830
//
// 0071e830  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0071e834  8bc1                 mov eax, ecx
// 0071e836  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0071e83a  894818               mov dword ptr [eax + 0x18], ecx
// 0071e83d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0071e841  8910                 mov dword ptr [eax], edx
// 0071e843  8b542404             mov edx, dword ptr [esp + 4]
// 0071e847  894814               mov dword ptr [eax + 0x14], ecx
// 0071e84a  89501c               mov dword ptr [eax + 0x1c], edx
// 0071e84d  c7402001000000       mov dword ptr [eax + 0x20], 1
// 0071e854  c21000               ret 0x10
// library xtp-13.2.1/Source\SkinFramework\XTPSkinObjectFrame.cpp (function ??0CCaptionButton@CXTPSkinObjectFrame@@QAE@HPAV1@IH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinObjectFrame.cpp
