// from server: 100% by auto
// roc 2007-03 00701ab0  unit: seg_00700000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00701ab0
//
// 00701ab0  83790400             cmp dword ptr [ecx + 4], 0
// 00701ab4  740a                 je 0x701ac0
// 00701ab6  8b4904               mov ecx, dword ptr [ecx + 4]
// 00701ab9  8b01                 mov eax, dword ptr [ecx]
// 00701abb  8b5004               mov edx, dword ptr [eax + 4]
// 00701abe  ffe2                 jmp edx
// 00701ac0  33c0                 xor eax, eax
// 00701ac2  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinManagerModuleList.cpp (function ?GetFirstModule@CXTPSkinManagerModuleList@@QAEPAUHINSTANCE__@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinManagerModuleList.cpp
