// from server: 100% by auto
// roc 2007-03 0071e330  unit: seg_00710000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071e330
//
// 0071e330  56                   push esi
// 0071e331  8bf1                 mov esi, ecx
// 0071e333  e882c90100           call 0x73acba
// 0071e338  85c0                 test eax, eax
// 0071e33a  7413                 je 0x71e34f
// 0071e33c  8bce                 mov ecx, esi
// 0071e33e  e881c80100           call 0x73abc4
// 0071e343  a900080000           test eax, 0x800
// 0071e348  b833010000           mov eax, 0x133
// 0071e34d  7405                 je 0x71e354
// 0071e34f  b838010000           mov eax, 0x138
// 0071e354  5e                   pop esi
// 0071e355  c3                   ret 
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectEdit.cpp (function ?GetClientBrushMessage@CXTPSkinObjectEdit@@MAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectEdit.cpp
