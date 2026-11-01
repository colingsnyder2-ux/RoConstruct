// from server: 100% by auto
// roc 2007-03 0071d500  unit: seg_00710000  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071d500
//
// 0071d500  56                   push esi
// 0071d501  8bf1                 mov esi, ecx
// 0071d503  e8ca11f0ff           call 0x61e6d2
// 0071d508  83f8ff               cmp eax, -1
// 0071d50b  7506                 jne 0x71d513
// 0071d50d  0bc0                 or eax, eax
// 0071d50f  5e                   pop esi
// 0071d510  c20400               ret 4
// 0071d513  8b4620               mov eax, dword ptr [esi + 0x20]
// 0071d516  6a00                 push 0
// 0071d518  6a00                 push 0
// 0071d51a  50                   push eax
// 0071d51b  ff1554ee7700         call dword ptr [0x77ee54]
// 0071d521  6a00                 push 0
// 0071d523  6a00                 push 0
// 0071d525  6800008000           push 0x800000
// 0071d52a  8bce                 mov ecx, esi
// 0071d52c  e81b13f0ff           call 0x61e84c
// 0071d531  6a20                 push 0x20
// 0071d533  6a00                 push 0
// 0071d535  6800020200           push 0x20200
// 0071d53a  8bce                 mov ecx, esi
// 0071d53c  e86111f0ff           call 0x61e6a2
// 0071d541  33c0                 xor eax, eax
// 0071d543  5e                   pop esi
// 0071d544  c20400               ret 4
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectComboBox.cpp (function ?OnCreate@CXTPSkinObjectComboBox@@IAEHPAUtagCREATESTRUCTA@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectComboBox.cpp
