// from server: 100% by auto
// roc 2007-03 00701ad0  unit: seg_00700000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00701ad0
//
// 00701ad0  83790400             cmp dword ptr [ecx + 4], 0
// 00701ad4  740a                 je 0x701ae0
// 00701ad6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00701ad9  8b01                 mov eax, dword ptr [ecx]
// 00701adb  8b5008               mov edx, dword ptr [eax + 8]
// 00701ade  ffe2                 jmp edx
// 00701ae0  33c0                 xor eax, eax
// 00701ae2  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerModuleList.cpp (function ?GetNextModule@CXTPSkinManagerModuleList@@QAEPAUHINSTANCE__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerModuleList.cpp
